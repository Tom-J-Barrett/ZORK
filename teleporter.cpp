#include "teleporter.h"
#include <QDebug>

Teleporter::Teleporter(QString desc, int inWeight)
    :description(desc),
      weight(inWeight)
{
    this->setPixmap(QPixmap(":/Images/teleporter.png"));
    this->setPos(470,100);
    this->setZValue(4);
    this->setScale(.05);
    invFlag = true;
}

QString Teleporter:: getDescription(){
    return description;
}

bool Teleporter:: getInvFlag(){
    return invFlag;
}

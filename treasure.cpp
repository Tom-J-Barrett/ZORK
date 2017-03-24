#include "treasure.h"
#include <QDebug>

Treasure::Treasure(QString desc, int inWeight)
    :description(desc),
      weight(inWeight)
{
    this->setPixmap(QPixmap(":/Images/Treasure.jpeg"));
    this->setPos(470,100);
    this->setZValue(4);
    this->setScale(.2);
    invFlag = false;
}

QString Treasure:: getDescription(){
    return description;
}

bool Treasure:: getInvFlag(){
    return invFlag;
}

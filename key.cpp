#include "key.h"
#include <QDebug>

Key::Key(const QString desc, const int inW)
  : description(desc),
      weight(inW)
{
    this->setPixmap(QPixmap(":/Images/key.png"));
    this->setPos(470,100);
    this->setZValue(4);
    this->setScale(.1);
    invFlag = true;
}

QString Key:: getDescription(){
    return description;
}

bool Key:: getInvFlag(){
    return invFlag;
}

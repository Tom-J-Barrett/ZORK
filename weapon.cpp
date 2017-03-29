#include "weapon.h"
#include <QDebug>

Weapon::Weapon(QString desc, int inW)
    : description(desc),
        weight(inW)
{
    this->setPixmap(QPixmap(":/Images/sword2.jpg"));
    this->setPos(470,100);
    this->setZValue(4);
    this->setScale(.4);
    invFlag = true;
}

QString Weapon::getDescription()
{
    return description;
}

bool Weapon:: getInvFlag(){
    return this->invFlag;
}

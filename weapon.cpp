#include "weapon.h"

Weapon::Weapon(string description, int inWeight)
{
    this->description = description;
    this->weight=inWeight;
    this->setPixmap(QPixmap(":/Images/sword2.jpg"));
    this->setPos(470,100);
    this->setZValue(4);
    this->setScale(.1);
}

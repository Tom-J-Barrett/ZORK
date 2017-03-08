#include "potion.h"

Potion::Potion(string description, int inWeight)
{
    this->description = description;
    this->weight=inWeight;
    this->setPixmap(QPixmap(":/Images/potion.jpg"));
    this->setPos(470,200);
    this->setZValue(4);
    this->setScale(.1);
}

#include "potion.h"
#include <string>

Potion::Potion(QString description, int inWeight)
{
    this->description = description;
    this->weight=inWeight;
    this->setPixmap(QPixmap(":/Images/potion.jpg"));
    this->setPos(470,100);
    this->setZValue(4);
    this->setScale(.1);
}

QString Potion:: getDescription(){
    return description;
}



#include "treasure.h"
#include <QDebug>

Treasure::Treasure(QString description, int inWeight)
{
    this->description = description;
    this->weight=inWeight;
    this->setPixmap(QPixmap(":/Images/Treasure.jpeg"));
    this->setPos(470,100);
    this->setZValue(4);
    this->setScale(.2);
    qDebug()<<"Treasure created"<<description;
}

QString Treasure:: getDescription(){
    return description;
}

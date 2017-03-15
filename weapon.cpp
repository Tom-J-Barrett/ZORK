#include "weapon.h"
#include <QDebug>

Weapon::Weapon(QString description, int inWeight)
{
    this->description = description;
    this->weight=inWeight;
    this->setPixmap(QPixmap(":/Images/sword2.jpg"));
    this->setPos(470,100);
    this->setZValue(4);
    this->setScale(.4);
    qDebug()<<"Weapon created";
}

QString Weapon::getDescription()
{
    return description;
}

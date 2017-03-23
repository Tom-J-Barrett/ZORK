#include "key.h"
#include <QDebug>

Key::Key(const QString description, const int inWeight)
{
    this->description = description;
    this->weight=inWeight;
    this->setPixmap(QPixmap(":/Images/key.png"));
    this->setPos(470,100);
    this->setZValue(4);
    this->setScale(.1);
    qDebug()<<"Key created"<<description;
}

QString Key:: getDescription(){
    return description;
}

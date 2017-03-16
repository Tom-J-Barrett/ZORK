#include "princess.h"

Princess::Princess()
{
    this->setPixmap(QPixmap(":/Images/princess.jpg"));
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    this->setPos(400,150);
    this->setZValue(2);
    this->setScale(.5);
}

QString Princess::getImage()
{
    return ":/Images/princess.jpg";
}



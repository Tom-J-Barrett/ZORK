#include "key.h"

Key::Key(QString description, int inWeight)
{
    this->description = description;
    this->weight=inWeight;
    this->setPixmap(QPixmap(":/Images/key.png"));
    this->setPos(470,100);
    this->setZValue(4);
    this->setScale(.1);
}

#include "key.h"

Key::Key(string description, int inWeight)
{
    this->description = description;
    this->weight=inWeight;
    this->setPixmap(QPixmap(":/Images/key.png"));
    this->setPos(470,200);
    this->setZValue(4);
    this->setScale(.1);
}

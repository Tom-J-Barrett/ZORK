#include "potion.h"
#include <string>
#include <QDebug>

Potion::Potion(const QString desc, const int inW)
    :description(desc),
      weight(inW)
{
    this->setPixmap(QPixmap(":/Images/potion.jpg"));
    this->setPos(470,100);
    this->setZValue(4);
    this->setScale(.5);
    invFlag = false;
    used = false;
}

QString Potion:: getDescription(){
    return description;
}

bool Potion:: getInvFlag(){
    return this->invFlag;
}

void Potion:: setUsed(){
    this->used = true;
}

bool Potion:: getUsed(){
    return used;
}


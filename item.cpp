#include "item.h"
#include <iostream>
#include <QGraphicsPixmapItem>
#include <QDebug>
using namespace std;

Item::Item(){
}

Item::Item (const QString description, const int inWeight) {

    this->description = description;
    this->weight=inWeight;
}

Item::Item(const QString description) {
    this->description = description;
}

int Item::getWeight()
{
    return weight;
}

QString Item::getDescription()
{
    return description;
}

bool Item::getInvFlag(){
    return invFlag;
}

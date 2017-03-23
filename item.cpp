#include "item.h"
#include <iostream>
#include <QGraphicsPixmapItem>
#include <QDebug>
using namespace std;

Item::Item(){
    qDebug()<<"Item created3";
}

Item::Item (const QString description, const int inWeight) {

    this->description = description;
    this->weight=inWeight;
    qDebug()<<"Item created";
    qDebug()<<description;
}

Item::Item(const QString description) {
    this->description = description;
    qDebug()<<"Item created2";
}

int Item::getWeight()
{
    return weight;
}

QString Item::getDescription()
{
    return description;
}



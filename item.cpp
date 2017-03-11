#include "item.h"
#include <iostream>
#include <QGraphicsPixmapItem>
#include <QDebug>
using namespace std;

Item::Item(){
    qDebug()<<"Item created3";
}

Item::Item (QString description, int inWeight) {

    this->description = description;
    this->weight=inWeight;
    qDebug()<<"Item created";
    qDebug()<<description;
}

Item::Item(QString description) {
    this->description = description;
    qDebug()<<"Item created2";
}

void Item::setWeight(int inWeight)
{
    if (inWeight > 9999 || inWeight < 0)
       cout << "weight invalid, must be 0<weight<9999" ;
    else
       weight = inWeight;
}

int Item::getWeight()
{
    return weight;
}

QString Item::getDescription()
{
    qDebug()<<"Get description";
    return description;
}



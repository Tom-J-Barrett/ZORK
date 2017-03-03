#include "item.h"
#include <iostream>
#include <QGraphicsPixmapItem>
#include <QDebug>
using namespace std;

Item::Item(){

}

Item::Item (string description, int inWeight) {

    description = description;
    setWeight(inWeight);
    this->setPixmap(QPixmap(":/Images/key.png"));
    this->setPos(470,200);
    this->setZValue(4);
    this->setScale(.1);
    //mousePressEvent(event);
}

void Item::mousePressEvent(QGraphicsSceneMouseEvent *event){
    qDebug()<<"clicked";

}

Item::Item(string description) {
    description = description;
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

string Item::getDescription()
{
    return description;
}



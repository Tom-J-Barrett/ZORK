#include "character.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsPixmapItem>


Character::Character(){

}


void getImage(){

}

void Character::decreaseHealth(){
    health=health-25;
}

void Character::resetHealth(){
    health=100;
}

void Character::increaseHealth(){
    health=health+25;
}

int Character::getHealth(){
    return health;
}


int Character::move(int x)
{
    qDebug()<<"Character moving";
}

/*void Character::keyPressEvent(QKeyEvent *event)
{

}*/

#include "character.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsPixmapItem>


Character::Character(){

}


QString Character::getImage(){
    return "";
}

void Character::decreaseHealth(){
    health=health-25;
}

void Character::decreaseHealthByAttack(const int damage){
    health=health-damage;
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
    return x;
}



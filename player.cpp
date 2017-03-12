#include "player.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

Player::Player()
{
    health=100;
    inventory = new Inventory();
    damage=25;
}


int Player::getHealth()
{
    return health;
}

Inventory * Player::getInventory(){
    return inventory;
}

void Player::decreaseHealth()
{
    if(health>=1)
        health--;
    else
    {
        qDebug()<<"You're dead";
        exit(EXIT_FAILURE);
    }

}

void Player::increaseHealth()
{
    health+=20;
}

int Player::getDamage(){
    return damage;
}

void Player::setDamage(int damage){
    this->damage=damage;
}





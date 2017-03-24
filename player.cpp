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

Player::~Player(){
    delete inventory;
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
        health=health-5;
    else
    {
        msgBox.setText("You are dead. Game Over.");
        msgBox.setInformativeText("");
        int ret = msgBox.exec();

         switch (ret) {
           case QMessageBox::Ok:
               exit(1);
               break;
           case QMessageBox::Cancel:
               exit(1);
               break;
           default:
               // should never be reached
               break;
         }
    }

}

void Player::increaseHealth(const int x)
{
    health+=x;
}

int Player::getDamage(){
    return damage;
}

void Player::setDamage(const int damage){
    this->damage=damage;
}





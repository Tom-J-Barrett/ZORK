#include "player.h"
#include "background.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

Player::Player()
{
    health=health+5;

    //this->setPixmap(QPixmap(":/Images/attack.png"));
    //this->setFlag(QGraphicsItem::ItemIsFocusable);
    //this->setPos(470,200);
    //this->setScale(50);
   // this->setZValue(3);
}


int Player::getHealth()
{

}

void Player::decreaseHealth()
{
    health=health+5;
}

void Player::increaseHealth()
{

}

#include "player.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

Player::Player()
{
    health=100;

    //this->setPixmap(QPixmap(":/Images/attack.png"));
    //this->setFlag(QGraphicsItem::ItemIsFocusable);
    //this->setPos(470,200);
    //this->setScale(50);
   // this->setZValue(3);
}


int Player::getHealth()
{
    return health;
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

}

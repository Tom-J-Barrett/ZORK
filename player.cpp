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
    qDebug()<<"oooooooooo";
  //  health--;
    qDebug()<<"poooooooooo";
}

void Player::increaseHealth()
{

}

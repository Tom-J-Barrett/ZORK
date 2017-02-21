#include "player.h"
#include "background.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

Player::Player()
{
    health=100;
    this->setPixmap(QPixmap(":/Images/attack.png"));
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setPos(470,200);
    //this->setScale(50);
    this->setZValue(3);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Space)
        qDebug() << "attack";
}

int Player::getHealth()
{

}

void Player::decreaseHealth()
{

}

void Player::increaseHealth()
{

}

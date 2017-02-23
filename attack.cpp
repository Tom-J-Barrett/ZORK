#include "monster.h"
#include "attack.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

Attack::Attack()
{
    qDebug() <<"Attacked";
    this->setPixmap(QPixmap(":/Images/attack.png"));
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    this->setPos(470,200);
    this->setZValue(3);
   // health=100;
}

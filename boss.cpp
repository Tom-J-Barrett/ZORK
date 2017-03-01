#include "boss.h"
#include "player.h"
#include "character.h"
#include "Monster.h"
#include "background.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include "attack.h"

Boss::Boss()
{
    this->setPixmap(QPixmap(":/Images/dragon.png"));
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    this->setPos(470,200);
    this->setZValue(2);
}


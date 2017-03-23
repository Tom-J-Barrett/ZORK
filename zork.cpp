#include "zork.h"
#include "player.h"
#include <QImage>
#include <QGraphicsPixmapItem>

Zork::Zork(QWidget *parent)
{
    this->setAttribute(Qt::WA_DeleteOnClose);
}

Zork::~Zork()
{
    delete player;
}

Player* Zork::play(){
    player = new Player();
    player->setDamage(25);
    return player;

}

#include "zork.h"
#include <QImage>
#include <QGraphicsPixmapItem>
#include "background.h"
#include "player.h"

Zork::Zork(QWidget *parent)
{
    this->setAttribute(Qt::WA_DeleteOnClose);

    play();

    setScene(backg);
    show();
}

void Zork:: play(){
    player = new Player();
    backg = new Background(player);
    currentRoom=backg->createRooms();
    backg->createExits();
    backg->setRoomExits(currentRoom);
    backg->setSceneRect(0,0,1000,500);
    backg->createRect();
    backg->createMonster();
    backg->createBoss();
    backg->createTextBox();
    backg->addText();
    backg->addToScene();
}

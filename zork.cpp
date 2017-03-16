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
    player->setDamage(25);
    backg = new Background(player);
    currentRoom=backg->createRooms();
    backg->createExits();
    backg->setRoomExits(currentRoom);
    backg->setSceneRect(0,0,1000,500);
    backg->createCave();
    backg->createMapGUI();
    backg->createMonster();
    backg->createPrincess();
    backg->createBoss();
    backg->createTextBox();
    backg->inventoryBox();
    backg->addText();
    backg->addToScene();

}

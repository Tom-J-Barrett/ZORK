#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include "inventory.h"

class Player{

public:
    Player();
    int health;

    //int * healthPtr;
    Inventory inventory;
    int getHealth();
    void decreaseHealth();
    void increaseHealth();
};

#endif // PLAYER_H

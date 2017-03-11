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
    Inventory* inventory;
    int getHealth();
    void decreaseHealth();
    void increaseHealth();
    Inventory * getInventory();
    int damage;
    int getDamage();
    void setDamage(int damage);
};

#endif // PLAYER_H

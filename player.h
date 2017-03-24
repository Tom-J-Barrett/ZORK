#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include "inventory.h"
#include <QMessageBox>

class Player{

public:
    Player();
    ~Player();
    int getHealth();
    void decreaseHealth();
    void increaseHealth(const int x);
    Inventory * getInventory();
    int getDamage();
    void setDamage(const int damage);

private:
    Inventory* inventory;
    int health;
    int damage;
    QMessageBox msgBox;
};

#endif // PLAYER_H

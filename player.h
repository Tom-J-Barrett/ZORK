#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>

class Player{

public:
    Player();
    int health=100;
    int getHealth();
    void decreaseHealth();
    void increaseHealth();
};

#endif // PLAYER_H

#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>

class Player: public QGraphicsPixmapItem{

public:
    Player();
    void keyPressEvent(QKeyEvent * event);
    int health;
    int getHealth();
    void decreaseHealth();
    void increaseHealth();
};

#endif // PLAYER_H

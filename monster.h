#ifndef MONSTER_H
#define MONSTER_H

#include <QGraphicsPixmapItem>
//#include "background.h"
#include "player.h"

class Monster: public QGraphicsPixmapItem{

public:
    Monster();
    Monster(Player * play);
    Player *p;
    void keyPressEvent(QKeyEvent * event);
    int move(int x);
    int health=100;
    int getHealth();
    void decreaseHealth();
    void resetHealth();
    int z;


};
#endif // MONSTER_H

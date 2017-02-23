#ifndef MONSTER_H
#define MONSTER_H

#include <QGraphicsPixmapItem>
//#include "background.h"

class Monster: public QGraphicsPixmapItem{

public:
    Monster();
    void keyPressEvent(QKeyEvent * event);
    int move(int x);
    int health=100;
    int getHealth();
    void decreaseHealth();
    void resetHealth();
    int z;


};
#endif // MONSTER_H

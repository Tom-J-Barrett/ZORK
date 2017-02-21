#ifndef MONSTER_H
#define MONSTER_H

#include <QGraphicsPixmapItem>

class Monster: public QGraphicsPixmapItem{

public:
    Monster();
    void keyPressEvent(QKeyEvent * event);
    int move(int x);
    int health=100;
    int getHealth();
    void decreaseHealth();


};
#endif // MONSTER_H

#ifndef CHARACTER_H
#define CHARACTER_H

#include <QGraphicsPixmapItem>

class Character: public QGraphicsPixmapItem{

public:
    Character();
    void keyPressEvent(QKeyEvent * event);
    int move(int x);
    int health=100;
    int getHealth();
    void decreaseHealth();
    void resetHealth();
    void increaseHealth();
    int z;

};

#endif // CHARACTER_H

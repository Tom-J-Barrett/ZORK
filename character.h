#ifndef CHARACTER_H
#define CHARACTER_H

#include <QGraphicsPixmapItem>

class Character: public QGraphicsPixmapItem{

public:
    Character();
    void keyPressEvent(QKeyEvent * event);
    int move(int x);
    int getHealth();
    void decreaseHealth();
    void resetHealth();
    void increaseHealth();

private:
    int health=100;
};

#endif // CHARACTER_H

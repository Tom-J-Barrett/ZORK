#ifndef CHARACTER_H
#define CHARACTER_H

#include <QGraphicsPixmapItem>
#include <string>
using namespace std;

class Character: public QGraphicsPixmapItem{

public:
    Character();
    //void keyPressEvent(QKeyEvent * event);
    virtual int move(int x);
    int getHealth();
    void decreaseHealth();
    void resetHealth();
    void increaseHealth();
    virtual QString getImage()=0;
    int z=0;
    void decreaseHealthByAttack(int damage);

private:
    int health=100;
    //int z=0;
};

#endif // CHARACTER_H

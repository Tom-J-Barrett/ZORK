#ifndef CHARACTER_H
#define CHARACTER_H

#include <QGraphicsPixmapItem>
#include <string>
using namespace std;

class Character: public QGraphicsPixmapItem{

public:
    Character();
    virtual int move(int x);
    int getHealth();
    void decreaseHealth();
    void resetHealth();
    void increaseHealth();
    virtual QString getImage()=0;
    void decreaseHealthByAttack(const int damage);
    int z=0;

private:
    int health=100;
};

#endif // CHARACTER_H

#ifndef CHARACTER_H
#define CHARACTER_H
#ifdef z
    #define z=0;
#endif
#ifdef health
    #define health=100;
#endif

#include <QGraphicsPixmapItem>
#include <string>
using namespace std;

class Character: public QGraphicsPixmapItem{

public:
    Character();
    virtual int move(int x);
    virtual int getHealth();
    virtual void decreaseHealth();
    virtual void resetHealth();
    virtual void increaseHealth();
    virtual QString getImage()=0;
    virtual void decreaseHealthByAttack(const int damage);
    int z;

protected:
    int health;
};

#endif // CHARACTER_H

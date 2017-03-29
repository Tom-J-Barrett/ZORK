#ifndef BOSS_H
#define BOSS_H

#include "character.h"
#include <string>
using namespace std;

class Boss: public Character
{

public:
    Boss();
    QString getImage();
    int move(int x);
    int getHealth();
    void decreaseHealthByAttack(const int);
private:
    int health=200;
};

#endif // BOSS_H

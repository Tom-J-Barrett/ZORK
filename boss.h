#ifndef BOSS_H
#define BOSS_H

#include "character.h"
#include <string>
using namespace std;

class Boss: public Character
{
public:
    Boss();
    string getImage();
    int move(int x);
   // void keyPressEvent(QKeyEvent *event);
};

#endif // BOSS_H

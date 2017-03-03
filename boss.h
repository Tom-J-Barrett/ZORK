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
};

#endif // BOSS_H

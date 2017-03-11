#ifndef MONSTER_H
#define MONSTER_H

#include "player.h"
#include "character.h"
#include <string>

class Monster: public Character{

public:
    Monster();
    QString getImage();
    int move(int x);
   // void keyPressEvent(QKeyEvent *event);
};
#endif // MONSTER_H

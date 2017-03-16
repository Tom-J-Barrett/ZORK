#ifndef PRINCESS_H
#define PRINCESS_H
#include "player.h"
#include "character.h"
#include <string>

class Princess: public Character{

public:
    Princess();
    QString getImage();
private:
    int health=10;
};
#endif // PRINCESS_H

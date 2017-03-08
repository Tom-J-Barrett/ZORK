#ifndef WEAPON_H
#define WEAPON_H
#include "item.h"

class Weapon: public Item
{
public:
    Weapon(string description, int inWeight);
private:
    string description;
    int weight;
};

#endif // WEAPON_H

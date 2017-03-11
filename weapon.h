#ifndef WEAPON_H
#define WEAPON_H
#include "item.h"

class Weapon: public Item
{
public:
    Weapon(QString description, int inWeight);
private:
    QString description;
    int weight;
};

#endif // WEAPON_H

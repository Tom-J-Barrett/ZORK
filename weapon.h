#ifndef WEAPON_H
#define WEAPON_H
#include "item.h"
#include <QDebug>

class Weapon: public Item
{
public:
    Weapon(QString description, int inWeight);
    QString getDescription();
private:
    QString description;
    int weight;
};

#endif // WEAPON_H

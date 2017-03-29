#ifndef WEAPON_H
#define WEAPON_H
#include "item.h"
#include <QDebug>

class Weapon: public Item
{
public:
    Weapon(QString desc,int inW);
    QString getDescription();
    bool getInvFlag();
private:
    const QString description;
    const int weight;
};

#endif // WEAPON_H

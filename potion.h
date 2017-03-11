#ifndef POTION_H
#define POTION_H

#include "item.h"

class Potion: public Item
{
public:
    Potion(QString description, int inWeight);
    QString getDescription();
private:
    QString description;
    int weight;
};

#endif // POTION_H

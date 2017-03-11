#ifndef TREASURE_H
#define TREASURE_H
#include "item.h"

class Treasure: public Item
{
public:
    Treasure(QString description, int inWeight);
private:
    QString description;
    int weight;
};

#endif // TREASURE_H
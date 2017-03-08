#ifndef TREASURE_H
#define TREASURE_H
#include "item.h"

class Treasure: public Item
{
public:
    Treasure(string description, int inWeight);
private:
    string description;
    int weight;
};

#endif // TREASURE_H

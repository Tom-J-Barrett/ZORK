#ifndef POTION_H
#define POTION_H

#include "item.h"

class Potion: public Item
{
public:
    Potion(string description, int inWeight);
    string getDescription();
private:
    string description;
    int weight;
};

#endif // POTION_H

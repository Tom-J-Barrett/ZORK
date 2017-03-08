#ifndef KEY_H
#define KEY_H

#include "item.h"

class Key: public Item
{
public:
    Key(string description, int inWeight);
private:
    string description;
    int weight;
};

#endif // KEY_H

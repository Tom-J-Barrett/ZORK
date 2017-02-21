#include "item.h"
#include <iostream>
using namespace std;

Item::Item (string description, int inWeight) {
    description = description;
    setWeight(inWeight);
}

Item::Item(string description) {
    description = description;
}

void Item::setWeight(int inWeight)
{
    if (inWeight > 9999 || inWeight < 0)
       cout << "weight invalid, must be 0<weight<9999" ;
    else
       weight = inWeight;
}

int Item::getWeight()
{
    return weight;
}

string Item::getDescription()
{
    return description;
}



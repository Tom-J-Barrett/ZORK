#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

class Item{
private:
    string description;
    int weight;

public:
    Item(string description, int inWeight);
    Item(string description);
    void pickUpItem(Item item);
    void dropItem(Item item);
    int getWeight();
    string getDescription();
    void setWeight(int inWeight);

};

#endif // ITEM_H

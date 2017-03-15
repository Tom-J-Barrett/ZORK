#ifndef INVENTORY_H
#define INVENTORY_H
#endif // INVENTORY_H
#include "item.h"
class Inventory{
private:

public:

    vector<Item*> itemsInInventory;
    Inventory();
    void showInventory();
    void addToInventory(Item *item);
    void removeFromInventory(Item item);
    int inventoryQty();
    vector<Item *> getInventoryList();
    void setInventoryList(vector<Item *> InventoryList);
};

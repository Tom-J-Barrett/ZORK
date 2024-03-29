#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"
class Inventory{
private:
    vector<Item*> itemsInInventory;
public:  
    Inventory();
    void showInventory();
    void addToInventory(Item *item);
    void removeFromInventory(Item item);
    int inventoryQty();
    vector<Item *> getInventoryList();
    void setInventoryList(vector<Item *> InventoryList);
};
#endif // INVENTORY_H

#include "inventory.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

Inventory::Inventory(){

}

void Inventory::showInventory()
{
    Item *itemDesc;
    QString itemDesc1;
    for( int i = 0; i < itemsInInventory.size(); i++){
       itemDesc = itemsInInventory[i];
       itemDesc1 = itemDesc->getDescription();
    }
}

void Inventory::addToInventory(Item *item){
    itemsInInventory.push_back(item);

}

vector<Item*> Inventory:: getInventoryList(){
    return itemsInInventory;
}

void Inventory::setInventoryList(vector<Item *> InventoryList)
{
    this->itemsInInventory=InventoryList;
}

int Inventory::inventoryQty(){
    return itemsInInventory.size();
}

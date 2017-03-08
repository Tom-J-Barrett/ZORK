#include "inventory.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

Inventory::Inventory(){

}

void Inventory::showInventory()
{
    Item *itemDesc;
    string itemDesc1;
    for( int i = 0; i < itemsInInventory.size(); i++){
       itemDesc = itemsInInventory[i];
       itemDesc1 = itemDesc->getDescription();
       qDebug () << QString::fromStdString(itemDesc1);

    }
}

void Inventory::addToInventory(Item *item){
    itemsInInventory.push_back(item);

}

void Inventory::removeFromInventory(Item item){

}

int Inventory::inventoryQty(){
    return itemsInInventory.size();
}

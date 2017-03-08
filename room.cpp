#include "Room.h"
#include <QDebug>

Room::Room(string description) {
    this->description = description;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
    if (north != NULL)
        exits["north"] = north;
    if (east != NULL)
        exits["east"] = east;
    if (south != NULL)
        exits["south"] = south;
    if (west != NULL)
        exits["west"] = west;
}

void Room::setMonster(bool monst)
{
    if(monst)
        monster=true;
    else
        monster=false;

}

void Room::setItem(bool i)
{
    if(i)
        itemPresent=true;
    else
        itemPresent=false;

}

void Room::setBoss(bool boss)
{
    if(boss)
        bossMonster=true;
    else
        bossMonster=false;
}

vector<string> Room::exitString()
{
    vector<string> list;
    list.clear();
    for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
        list.push_back(i->first);	// access the "first" element of the pair (direction as a string)
    return list;
}

bool Room::monsterInRoom()
{
    return monster;
}

bool Room::bossInRoom()
{
    return bossMonster;
}

string Room::getDescription()
{
    return description;
}

bool Room::itemInRoom()
{
    return itemPresent;
}

vector<Room> Room::rooms()
{
    vector<Room> list;
    list.clear();
    for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
        list.push_back(i->first);	// access the "first" element of the pair (direction as a string)
    return list;
}

Room* Room::nextRoom(string direction) {

    map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
    {

        return NULL; // if exits.end() was returned, there's no room in that direction.
    }

    return next->second; // If there is a room, remove the "second" (Room*)
                // part of the "pair" (<string, Room*>) and return it.
}

void Room::addItem(Item *inItem) {
    this->item =inItem;
    itemsInRoom.push_back(inItem);
}

int Room::numberOfItems() {
    return itemsInRoom.size();
}
/*void Room::addItem(Item *inItem) {
    //cout <<endl;
    //cout << "Just added" + inItem->getLongDescription();
    itemsInRoom.push_back(*inItem);
}

string Room::displayItem() {
    string tempString = "items in room = ";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "no items in room";
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + itemsInRoom[x].getShortDescription() + "  " ;
            x++;
            }
        }
    return tempString;
    }

int Room::numberOfItems() {
    return itemsInRoom.size();
}

int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x].getShortDescription());
            if (tempFlag == 0) {
                itemsInRoom.erase(itemsInRoom.begin()+x);
                return x;
            }
            x++;
            }
        }
    return -1;
}*/
void addItemToRoom(Room room){
//if(room.item != NULL)
//{

//}
}

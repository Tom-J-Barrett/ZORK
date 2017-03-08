#ifndef ROOM_H
#define ROOM_H
#include <map>
#include <string>
#include <vector>
#include "item.h"

using namespace std;
using std::vector;

class Room {
private:

    map<string, Room*> exits;
    bool monster;
    bool bossMonster;
public:
    string description;

    vector<Item*> itemsInRoom;

    Room(string description);
    void setExits(Room *north, Room *east, Room *south, Room *west);
    void setMonster(bool);
    void setBoss(bool);
    vector<string> exitString();
    string getDescription();

    Item *item;

    bool monsterInRoom();
    bool bossInRoom();
    vector<Room> rooms();
    Room* nextRoom(string direction);
    void addItem(Item *inItem);
    void addItemToRoom(Room *room);
    int numberOfItems();
    /*void addItem(Item *inItem);
    string displayItem();
    int isItemInRoom(string inString);*/
};

#endif // ROOM_H

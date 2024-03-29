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
    bool monster = false;
    bool bossMonster = false;
    bool princess = false;
    bool itemPresent=false;
    string description;
    bool bossIsDead=false;
    bool canEnter;

public:
    Room(string description);
    vector<Item*> itemsInRoom;
    Item *item;
    void setExits(Room *north, Room *east, Room *south, Room *west);
    void setMonster(bool);
    void setItem(bool i);
    void setBoss(bool);
    void setPrincess(bool);
    vector<string> exitString();
    string getDescription();
    bool itemInRoom();
    bool monsterInRoom();
    bool bossInRoom();
    bool princessInRoom();
    vector<Room> rooms();
    Room* nextRoom(string direction);
    void addItem(Item *inItem);
    void addItemToRoom(Room *room);
    int numberOfItems();
    bool getBossIsDead();
    void setbossIsDead(bool dead);
    bool getCanEnter();
    void setCanEnter(bool);
};

#endif // ROOM_H

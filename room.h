#ifndef ROOM_H
#define ROOM_H
#include <map>
#include <string>
#include <vector>

//#include "item.h"
using namespace std;
using std::vector;

class Room {
private:

    map<string, Room*> exits;
    bool monster;
public:
    string description;
    Room(string description);
    void setExits(Room *north, Room *east, Room *south, Room *west);
    void setMonster(bool);
    vector<string> exitString();
    string getDescription();
    bool monsterInRoom();
    vector<Room> rooms();
    Room* nextRoom(string direction);
    /*void addItem(Item *inItem);
    string displayItem();
    int isItemInRoom(string inString);*/
};

#endif // ROOM_H

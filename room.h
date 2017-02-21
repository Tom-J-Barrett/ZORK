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
    string description;
    map<string, Room*> exits;
public:
    Room(string description);
    void setExits(Room *north, Room *east, Room *south, Room *west);
    vector<string> exitString();
    vector<Room> rooms();
    Room* nextRoom(string direction);
    /*void addItem(Item *inItem);
    string displayItem();
    int isItemInRoom(string inString);*/
};

#endif // ROOM_H

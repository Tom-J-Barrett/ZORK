#ifndef TREASURE_H
#define TREASURE_H
#include "item.h"

class Treasure: public Item
{
public:
    Treasure(QString description, int inWeight);
    QString getDescription();
    bool getInvFlag();
private:
    const QString description;
    const int weight;

};

#endif // TREASURE_H

#ifndef TELEPORTER_H
#define TELEPORTER_H
#include "item.h"

class Teleporter: public Item
{
public:
    Teleporter(QString description, int inWeight);
    QString getDescription();
    bool getInvFlag();
private:
    const QString description;
    const int weight;

};

#endif // TELEPORTER_H

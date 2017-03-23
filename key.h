#ifndef KEY_H
#define KEY_H

#include "item.h"

class Key: public Item
{
public:
    Key(const QString description, const int inWeight);
    QString getDescription();
private:
    QString description;
    int weight;
};

#endif // KEY_H

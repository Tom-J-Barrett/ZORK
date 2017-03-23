#ifndef KEY_H
#define KEY_H

#include "item.h"

class Key: public Item
{
    friend class Background;
public:
    Key(QString description, int inWeight);
    QString getDescription();
private:
    QString description;
    int weight;
};

#endif // KEY_H

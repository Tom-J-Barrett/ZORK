#ifndef POTION_H
#define POTION_H

#include "item.h"

class Potion: public Item
{
public:
    Potion(const QString desc, const int inW);
    QString getDescription();
    QString setDescription(QString);
    bool getInvFlag();
    void setUsed();
    bool getUsed();

private:
    const QString description;
    const int weight;
    bool used;
};

#endif // POTION_H

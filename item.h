#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <QGraphicsPixmapItem>
using namespace std;

class Item: public QGraphicsPixmapItem {
    friend class Background;
private:
    QString description;
    int weight;

public:
    Item();
    Item(const QString description, const int inWeight);
    Item(const QString description);
    int getWeight();
    virtual QString getDescription();
};

#endif // ITEM_H

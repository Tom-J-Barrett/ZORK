#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <QGraphicsPixmapItem>
using namespace std;

class Item: public QGraphicsPixmapItem {
private:
    QString description;
    int weight;

public:
    Item();
    Item(QString description, int inWeight);
    Item(QString description);
    int getWeight();
    virtual QString getDescription();
    void setWeight(int inWeight);
};

#endif // ITEM_H

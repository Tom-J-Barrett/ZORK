#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <QGraphicsPixmapItem>
using namespace std;

class Item: public QGraphicsPixmapItem {
private:
    string description;
    int weight;

public:
    Item();
    Item(string description, int inWeight);
    Item(string description);
    void pickUpItem(Item item);
    void dropItem(Item item);
    int getWeight();
    string getDescription();
    void setWeight(int inWeight);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // ITEM_H

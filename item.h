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

protected:
    bool invFlag;

public:
    Item();
    Item(const QString desc, const int inW);
    Item(const QString description);
    int getWeight();
    virtual QString getDescription();
    void setWeight(int inWeight);
    bool getInvFlag();
};

#endif // ITEM_H

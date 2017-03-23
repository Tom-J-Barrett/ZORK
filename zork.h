#ifndef ZORK_H
#define ZORK_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "monster.h"
#include "player.h"
#include "myvector.h"

class Zork : public QGraphicsView
{
public:
    Zork(QWidget * parent=0);
    ~Zork();
    Player* play();

    Player* player;

private:
    myVector<QString> * controls;
};
#endif // ZORK_H

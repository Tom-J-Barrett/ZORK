#ifndef ZORK_H
#define ZORK_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "monster.h"
#include "background.h"
#include "player.h"

class Zork : public QGraphicsView
{
public:
    Zork(QWidget * parent=0);
    Background * backg;

   // monster * vampire;


};

#endif // ZORK_H

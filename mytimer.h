#ifndef MYTIMER_H
#define MYTIMER_H
#include "Monster.h"
#include "player.h"
#include "room.h"
#include <QtCore>

class MyTimer : public QObject
{
    Q_OBJECT
public:
    MyTimer(Monster * vampire, Player * p, Room* r);
    QTimer * timer;
    Player * play;
    Monster * vamp;
    Room * room;
    int x=0;
    int health=0;
    void StopTimer();
public slots:
    void MySlot();
};

#endif // MYTIMER_H

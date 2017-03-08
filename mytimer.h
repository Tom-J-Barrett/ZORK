#ifndef MYTIMER_H
#define MYTIMER_H
#include "Monster.h"
#include "player.h"
#include "room.h"
#include "boss.h"
#include "character.h"
#include <QtCore>

class MyTimer : public QObject
{
    Q_OBJECT
public:
    MyTimer(Monster * enemy, Player * p, Room* r);
    MyTimer(Boss * enemy, Player * p, Room* r);
    void StopTimer();

public slots:
    void monsterSlot();
    void dragonSlot();

private:
    QTimer * timer;
    Player * play;
    Character * vamp;
    Monster * vampire;
    Boss * dragon;
    Room * room;
    int x=0;
    int health=0;
};

#endif // MYTIMER_H

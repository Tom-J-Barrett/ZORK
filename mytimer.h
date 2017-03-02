#ifndef MYTIMER_H
#define MYTIMER_H
#include "Monster.h"
#include "player.h"
#include "room.h"
#include "character.h"
#include <QtCore>

class MyTimer : public QObject
{
    Q_OBJECT
public:
    MyTimer(Character * vampire, Player * p, Room* r);
    void StopTimer();

public slots:
    void MySlot();

private:
    QTimer * timer;
    Player * play;
    Character * vamp;
    Room * room;
    int x=0;
    int health=0;
};

#endif // MYTIMER_H

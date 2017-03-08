#include "mytimer.h"
#include <QtCore>
#include <QDebug>
#include <background.h>
#include <Monster.h>
#include <QSignalMapper>

MyTimer::MyTimer(Monster * enemy, Player * p, Room* r)
{
    vampire=enemy;

    room=r;
    play=p;
    timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this, SLOT(monsterSlot()));
    timer->start(1000);
    x=0;
}

MyTimer::MyTimer(Boss * enemy, Player * p, Room* r)
{
    dragon=enemy;

    room=r;
    play=p;
    timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this, SLOT(dragonSlot()));
    timer->start(1000);
    x=0;
}

void MyTimer::StopTimer()
{
    timer->stop();
}

void MyTimer::monsterSlot()
{
    vampire->setPixmap(QPixmap(":/Images/vampire.png"));
    if(vampire)
        health=vampire->getHealth();
    qDebug()<<vampire->getHealth();
    if(health<=0){
        vampire->setVisible(false);
        room->setMonster(false);
    }
    else{
        x=vampire->move(x);
    }

    play->decreaseHealth();
}

void MyTimer::dragonSlot()
{
    dragon->setPixmap(QPixmap(":/Images/dragon.png"));
    if(dragon)
        health=dragon->getHealth();
    qDebug()<<dragon->getHealth();
    if(health<=0){
        dragon->setVisible(false);
        room->setMonster(false);
    }
    else{
        x=dragon->move(x);
    }

    play->decreaseHealth();
}


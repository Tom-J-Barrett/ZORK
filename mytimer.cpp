#include "mytimer.h"
#include <QtCore>
#include <QDebug>
#include <background.h>
#include <Monster.h>
#include <QSignalMapper>

MyTimer::MyTimer(Character * enemy, Player * p, Room* r)
{
    villian=enemy;

    room=r;
    play=p;
    timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this, SLOT(villianSlot()));
    timer->start(1000);
    x=0;
}

MyTimer::~MyTimer()
{
    timer->deleteLater();
    room=nullptr;
    play=nullptr;
    villian=nullptr;
}

void MyTimer::stopTimer()
{
    timer->stop();
}

void MyTimer::villianSlot()
{
    villian->setPixmap(QPixmap(villian->getImage()));
    if(villian)
        health=villian->getHealth();
    if(health<=0){
        villian->setVisible(false);
        if(room->monsterInRoom()==true){
            room->setMonster(false);
        }
        if(room->bossInRoom()==true){
            room->setBoss(false);
            room->setbossIsDead(true);
        }
    }
    else{
        x=villian->move(x);
    }
    if(-1==x)
        play->decreaseHealth();
}




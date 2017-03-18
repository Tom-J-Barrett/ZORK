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
}

void MyTimer::stopTimer()
{
    timer->stop();
    qDebug()<<"Timer stopped";
}

void MyTimer::villianSlot()
{
    villian->setPixmap(QPixmap(villian->getImage()));
    if(villian)
        health=villian->getHealth();

    if(health<=0){
        villian->setVisible(false);
        room->setMonster(false);
    }
    else{
        qDebug()<<"MOOOOOOVe";
        x=villian->move(x);
    }
    if(-1==x)
        play->decreaseHealth();
}




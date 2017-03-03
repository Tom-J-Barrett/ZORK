#include "mytimer.h"
#include <QtCore>
#include <QDebug>
#include <background.h>
#include <Monster.h>
#include <QSignalMapper>

MyTimer::MyTimer(Character * enemy, Player * p, Room* r)
{
    vamp=enemy;

    room=r;
    play=p;
    timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this, SLOT(MySlot()));
    timer->start(1000);
    x=0;
}

void MyTimer::StopTimer()
{
    timer->stop();
}

void MyTimer::MySlot()
{
    //vamp->setPixmap(QPixmap(":/Images/vampire.png"));
    if(vamp)
        health=vamp->getHealth();
    qDebug()<<vamp->getHealth();
    if(health<=0){
        vamp->setVisible(false);
        room->setMonster(false);
    }
    else{
        x=vamp->move(x);
    }

    play->decreaseHealth();
}

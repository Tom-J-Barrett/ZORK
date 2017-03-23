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
    qDebug()<<"ljarfraiejrgbaerhga;ohgeilahenblaktnbahltkha"<<"      "<< health;
    if(health<=0){
        qDebug()<<"ljarfraiejrgbaerhga;ohgeilahenblaktnbahltkha";
        villian->setVisible(false);
        if(room->monsterInRoom()==true){
            room->setMonster(false);
        }
        if(room->bossInRoom()==true){
            qDebug()<<"ljarfraiejrgbaerhga;ohgeilahenblaktnbahltkha";
            room->setBoss(false);
            room->setbossIsDead(true);
        }
    }
    else{
        qDebug()<<"MOOOOOOVe";
        x=villian->move(x);
    }
    if(-1==x)
        play->decreaseHealth();
}




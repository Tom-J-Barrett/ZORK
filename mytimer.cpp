#include "mytimer.h"
#include <QtCore>
#include <QDebug>
#include <background.h>
#include <Monster.h>
#include <QSignalMapper>

MyTimer::MyTimer(Monster * vampire)
{
    vamp=vampire;
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
    if(vamp)
        health=vamp->getHealth();

    if(health<=0)
    {
       // delete vamp;
       // vamp=NULL;
        vamp->setVisible(false);
        qDebug()<<"vamp is null";
    }
    else if(vamp==NULL)
    {
        qDebug()<<"vamp is deleted";
    }
    else
    {
        qDebug()<<"vamp is moved";
        x=vamp->move(x);
    }
}

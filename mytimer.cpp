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
    health=vamp->getHealth();
    if(health<=0)
        delete vamp;
    else
        x=vamp->move(x);
}

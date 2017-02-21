#ifndef MYTIMER_H
#define MYTIMER_H
#include "Monster.h"
#include <QtCore>

class MyTimer : public QObject
{
    Q_OBJECT
public:
    MyTimer(Monster * vampire);
    QTimer * timer;
    Monster * vamp;
    int x=0;
    int health=0;
    void StopTimer();
public slots:
    void MySlot();
};

#endif // MYTIMER_H

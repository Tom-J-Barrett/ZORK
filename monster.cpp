#include "Monster.h"
#include "background.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include "attack.h"

Monster::Monster()
{
    this->setPixmap(QPixmap(":/Images/vampire.png"));
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    this->setPos(470,200);
    this->setZValue(2);
   // health=100;
}
Monster::Monster(Player * play)
{
    p=play;
    this->setPixmap(QPixmap(":/Images/vampire.png"));
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    this->setPos(470,200);
    this->setZValue(2);
   // health=100;
}

void Monster::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left && x()>=260){
           setPos(x()-10,y());
    }
    else if(event->key()==Qt::Key_Right && x()<=690){
       setPos(x()+10,y());
    }
    else if(event->key()==Qt::Key_Up && y()>=110){
       setPos(x(),y()-10);
    }
    else if(event->key()==Qt::Key_Down && y()<=310){
       setPos(x(),y()+10);
    }
    else if(event->key()==Qt::Key_Space)
    {
            if(this->scenePos()==QPointF(470,200))
            {
                qDebug()<< this->scenePos();
                health=health-25;
                this->setPixmap(QPixmap(":/Images/vampireAttacked.png"));
                z=1;
            }

    }
}

int Monster::getHealth(){
    return health;
}

void Monster::resetHealth(){
    health=100;
}

int Monster::move(int x)
{
    if(z=1)
        this->setPixmap(QPixmap(":/Images/vampire.png"));

    if(x==0)
    {
        this->setPos(490,200);
        x=1;
        return x;
    }
    else if(x==1)
    {
       this->setPos(470,200);
       x=-1;
       return x;
    }
    else if(x==-1)
    {
        this->setPos(450,200);
        x=2;
        return x;
    }
    else if(x==2)
    {
        this->setPos(470,200);
        x=3;
        return x;
    }
    else if(x==3)
    {
        this->setPos(470,220);
        x=4;
        return x;
    }
    else if(x==4)
    {
        this->setPos(470,200);
        x=5;
        return x;
    }
    else if(x==5)
    {
        this->setPos(470,180);
        x=6;
        return x;
    }
    else if(x==6)
    {
        this->setPos(470,200);
        x=0;
        return x;
    }

}




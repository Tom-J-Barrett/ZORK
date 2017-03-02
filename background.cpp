#include "background.h"
#include "monster.h"
#include "room.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QMessageBox>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QDebug>
#include <QObject>
#include "buttonaction.h"
#include "mytimer.h"
#include "background.h"
#include "player.h"
#include <QString>
#include <string>
#include "boss.h"


//constructor that sets blank window and creates rooms
Background::Background(Player * play){
    player=play;
}

//Sets a new scne when you move rooms
void Background::setScene(string direction)
{
    nextRoom = currentRoom->nextRoom(direction);

    currentRoom=nextRoom;

    clearBackground();

    setRoomExits(currentRoom);

    addToScene();
}

Room * Background::createRooms(){

    a= new Room("a");
    b= new Room("b");
    c= new Room("c");
    d= new Room("d");
    e= new Room("e");
    f= new Room("f");
    g= new Room("g");
    h= new Room("h");
    i= new Room("i");
    j= new Room("j");
    return a;

}

void Background::createExits(){

    //         (N, E, S, W)
    a->setExits(f, b, d, c);
    a->setMonster(true);

    b->setExits(NULL, NULL, NULL, a);
    b->setBoss(true);

    c->setExits(NULL, a, NULL, NULL);
    c->setMonster(true);

    d->setExits(a, e, NULL, i);

    e->setExits(NULL, NULL, NULL, d);
    e->setMonster(true);

    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    g->setMonster(true);

    h->setExits(NULL, f, NULL, NULL);

    i->setExits(NULL, d, j, NULL);
    i->setMonster(true);

    j->setExits(i, NULL, NULL, NULL);
}

//creates buttons depending on room exits
void Background::setRoomExits(Room * r){
    currentRoom = r;

    vector<string> listOfExits= currentRoom->exitString();
    vector<Room> roomsToExit= currentRoom->rooms();
    for(int i=0;i<listOfExits.size();i++)
    {
        if(listOfExits[i]=="north"){
            button1= new QPushButton();
            button1->move(300,125);
            button1->raise();
            button1->setText("North");
            delB1=1;
            this->addWidget(button1);

            connect(button1,SIGNAL(released()),this, SLOT(on_button1_clicked()));
        }
        else if(listOfExits[i]=="south"){
            button2= new QPushButton();
            button2->move(625,125);
            button2->setText("South");
            button2->raise();
            delB2=1;
            connect(button2,SIGNAL(released()),this, SLOT(on_button2_clicked()));
            this->addWidget(button2);
        }
        else if(listOfExits.at(i)=="east"){
            button3= new QPushButton();
            button3->move(300,335);
            button3->setText("East");
            button3->raise();
            delB3=1;
            connect(button3,SIGNAL(released()),this, SLOT(on_button3_clicked()));
            this->addWidget(button3);
        }
        else if(listOfExits.at(i)=="west"){
            button4= new QPushButton();
            button4->move(625,335);
            button4->setText("West");
            button4->raise();
            delB4=1;
            this->addWidget(button4);
            connect(button4,SIGNAL(released()),this, SLOT(on_button4_clicked()));
        }

    }
}
void Background::createRect(){
    rect= new QGraphicsRectItem();
    rect->setRect(250,100,500,300);
    rect->setBrush(Qt::green);
    rect->setZValue(-1);

}

void Background::createMonster(){
    qDebug()<<"Test2";
    vampire = new Monster();
    vampire->setPixmap(QPixmap(":/Images/vampire.png"));
    vampire->setFlag(QGraphicsItem::ItemIsFocusable);
    vampire->setFocus();
    vampire->setPos(470,200);
    vampire->setZValue(3);
}

void Background::createBoss(){
    dragon = new Boss();
    dragon->setPixmap(QPixmap(":/Images/dragon.jpeg"));
    dragon->setFlag(QGraphicsItem::ItemIsFocusable);
    dragon->setFocus();
    dragon->setPos(470,200);
    dragon->setZValue(2);
}

void Background:: createTextBox(){
    smallEditor = new QTextEdit;
    smallEditor->move(250,400);
    smallEditor->setReadOnly(true);
}

void Background:: addText(){
     string x="You are in Room "+currentRoom->getDescription();
     smallEditor->setPlainText(QString::fromStdString(x));
}

//adds monster and rectangle to scene
void Background::addToScene(){
    if(!(vampire->isVisible() ) && currentRoom->monsterInRoom()){
        vampire->setVisible(true);
    }
    if(!(currentRoom->monsterInRoom()))
        vampire->setVisible(false);

    this->addWidget(smallEditor);
    this->addItem(vampire);
    timer = new MyTimer(vampire, player, currentRoom);
    this->addItem(rect);
    vampire->setPixmap(QPixmap(":/Images/vampire.png"));
    vampire->setFocus();
}


void Background::on_button1_clicked()
{

    setScene("north");
}

void Background::on_button2_clicked()
{

    setScene("south");
}
void Background::on_button3_clicked()
{

    setScene("east");
}
void Background::on_button4_clicked()
{

    setScene("west");
}

void Background::clearBackground(){

    if(delB1)
    {
        button1->deleteLater();
        delB1=0;
    }
    if(delB2)
    {
        button2->deleteLater();
        delB2=0;
    }
    if(delB3)
    {
       button3->deleteLater();
        delB3=0;
    }
    if(delB4)
    {
        button4->deleteLater();
        delB4=0;
    }

    this->removeItem(vampire);
    this->removeItem(rect);

    addText();

    vampire->resetHealth();

    timer->StopTimer();
    delete timer;
}








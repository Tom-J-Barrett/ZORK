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
#include <key.h>
#include "boss.h"
#include "treasure.h"
#include "weapon.h"
#include "potion.h"


//constructor that sets blank window and creates rooms
Background::Background(Player * play){
    player=play;
    inventoryContString = "";
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
    a->addItem(new Key("item a", 20));
    a->setItem(true);

    b= new Room("b");
    b->addItem(new Potion("Potion capable of restoring 20 hearts!",10));
    b->setItem(true);

    c= new Room("c");
    c->addItem(new Weapon("Hero's sword",30));
    c->setItem(true);

    d= new Room("d");
    d->addItem(new Treasure("Treasure!!!!!",50));
    d->setItem(true);

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
            button1->move(450,125);
            button1->raise();
            button1->setText("North");
            delB1=1;
            this->addWidget(button1);

            connect(button1,SIGNAL(released()),this, SLOT(on_button1_clicked()));
        }
        else if(listOfExits[i]=="south"){
            button2= new QPushButton();
            button2->move(450,335);
            button2->setText("South");
            button2->raise();
            delB2=1;
            connect(button2,SIGNAL(released()),this, SLOT(on_button2_clicked()));
            this->addWidget(button2);
        }
        else if(listOfExits.at(i)=="east"){
            button3= new QPushButton();
            button3->move(650,225);
            button3->setText("East");
            button3->raise();
            delB3=1;
            connect(button3,SIGNAL(released()),this, SLOT(on_button3_clicked()));
            this->addWidget(button3);
        }
        else if(listOfExits.at(i)=="west"){
            button4= new QPushButton();
            button4->move(275,225);
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
    dragon->setPixmap(QPixmap(":/Images/dragon.png"));
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

void Background:: createInventoryBox(string inventoryString){
    inventoryEditor = new QTextEdit;
    inventoryEditor->move(400,400);
    inventoryEditor->setReadOnly(true);
    inventoryContString += inventoryString;
    inventoryEditor->setPlainText(QString::fromStdString(inventoryContString));
}

void Background:: addText(){
     string x="You are in Room "+currentRoom->getDescription();
     smallEditor->setPlainText(QString::fromStdString(x));
}


//adds monster and rectangle to scene
void Background::addToScene(){
    if(currentRoom->monsterInRoom()){
        vampire->setVisible(true);
        vampire->setFocus();
        timer = new MyTimer(vampire, player, currentRoom);
        qDebug()<<"ukhv";
    }

    if(!(currentRoom->monsterInRoom()))
        vampire->setVisible(false);

    if(!(dragon->isVisible() ) && currentRoom->bossInRoom()){
        dragon->setVisible(true);
        dragon->setFocus();
        timer = new MyTimer(dragon, player, currentRoom);
    }

    if(!(currentRoom->bossInRoom())){
        dragon->setVisible(false);
    }

    this->addWidget(smallEditor);
    this->addWidget(inventoryEditor);
    this->addItem(vampire);
    this->addItem(dragon);
    this->addItem(rect);

    if(currentRoom->itemInRoom()){
        item=currentRoom->item;
        item->setVisible(true);
        this->addItem(item);
    }

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
    this->removeItem(dragon);

    if(item){
        this->removeItem(item);

    }

    addText();

    vampire->resetHealth();
    dragon->resetHealth();

    timer->StopTimer();
    delete timer;

}

void Background::keyPressEvent(QKeyEvent *event)
{
    if(currentRoom->monsterInRoom()){
        if(event->key()==Qt::Key_X)
        {
                if(vampire->scenePos()==QPointF(470,200)){
                    vampire->decreaseHealth();
                    vampire->setPixmap(QPixmap(":/Images/vampireAttacked.png"));
                    vampire->z=1;
                }

        }
    }
    else if(currentRoom->bossInRoom()){
        if(event->key()==Qt::Key_X)
        {
                if(dragon->scenePos()==QPointF(470,200)){
                    dragon->decreaseHealth();
                    dragon->setPixmap(QPixmap(":/Images/dragon.png"));
                    dragon->z=1;
                }
        }
    }



    if(event->key()==Qt::Key_P)
    {
            if(currentRoom->itemsInRoom.size() > 0)
            {
                inventory=player->getInventory();
                inventory->addToInventory(currentRoom->item);
                createInventoryBox(currentRoom->item->getDescription());
                this->addWidget(inventoryEditor);
                item->setVisible(false);
                currentRoom->setItem(false);
            }

    }
}






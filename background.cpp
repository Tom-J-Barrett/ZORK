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
    clearBackground();

    nextRoom = currentRoom->nextRoom(direction);

    currentRoom=nextRoom;

    setRoomExits(currentRoom);

    addToScene();

    createMapGUI();
}

void Background::refreshScene(){
    clearBackground();

    setRoomExits(currentRoom);

    addToScene();

    createMapGUI();
}

Room * Background::createRooms(){

    a= new Room("a");
    key=new Key("Rusty Key",20);
    a->addItem(key);
    a->setItem(true);


    b= new Room("b");
    potion= new Potion("Potion capable of restoring 20 hearts!",10);
    b->addItem(potion);
    b->setItem(true);

    c= new Room("c");
    weapon=new Weapon("Hero's sword",30);
    c->addItem(weapon);
    c->setItem(true);

    d= new Room("d");
    treasure=new Treasure("Gold and jewels",50);
    d->addItem(treasure);
    d->setItem(true);

    e= new Room("e");
    f= new Room("f");
    g= new Room("g");
    h= new Room("h");
    i= new Room("i");
    j= new Room("j");
    return j;

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
            button1->move(450,50);
            button1->raise();
            button1->setText("North");
            delB1=1;
            this->addWidget(button1);

            connect(button1,SIGNAL(released()),this, SLOT(on_button1_clicked()));
        }
        else if(listOfExits[i]=="south"){
            button2= new QPushButton();
            button2->move(450,435);
            button2->setText("South");
            button2->raise();
            delB2=1;
            connect(button2,SIGNAL(released()),this, SLOT(on_button2_clicked()));
            this->addWidget(button2);
        }
        else if(listOfExits.at(i)=="east"){
            button3= new QPushButton();
            button3->move(750,225);
            button3->setText("East");
            button3->raise();
            delB3=1;
            connect(button3,SIGNAL(released()),this, SLOT(on_button3_clicked()));
            this->addWidget(button3);
        }
        else if(listOfExits.at(i)=="west"){
            button4= new QPushButton();
            button4->move(175,225);
            button4->setText("West");
            button4->raise();
            delB4=1;
            this->addWidget(button4);
            connect(button4,SIGNAL(released()),this, SLOT(on_button4_clicked()));
        }

    }
}
void Background::createCave(){
    rect= new QGraphicsPixmapItem();
    rect->setPos(50,25);
    rect->setPixmap(QPixmap(":/Images/cave.jpg"));
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
    smallEditor->move(250,475);
    smallEditor->setReadOnly(true);
    this->addWidget(smallEditor);
}

void Background::createMapGUI()
{

    RoomA= new QGraphicsRectItem();
    RoomB= new QGraphicsRectItem();
    RoomC= new QGraphicsRectItem();
    RoomD= new QGraphicsRectItem();
    RoomE= new QGraphicsRectItem();
    RoomF= new QGraphicsRectItem();
    RoomG= new QGraphicsRectItem();
    RoomH= new QGraphicsRectItem();
    RoomI= new QGraphicsRectItem();
    RoomJ= new QGraphicsRectItem();

    RoomA->setRect(10,10,10,10);
    RoomA->setZValue(4);
    this->addItem(RoomA);

    RoomB->setRect(20,10,10,10);
    RoomB->setZValue(5);
    this->addItem(RoomB);

    RoomC->setRect(0,10,10,10);
    RoomC->setZValue(5);
    this->addItem(RoomC);

    RoomD->setRect(10,20,10,10);
    RoomD->setZValue(5);
    this->addItem(RoomD);

    RoomE->setRect(20,20,10,10);
    RoomE->setZValue(5);
    this->addItem(RoomE);

    RoomF->setRect(10,0,10,10);
    RoomF->setZValue(5);
    this->addItem(RoomF);

    RoomG->setRect(20,0,10,10);
    RoomG->setZValue(5);
    this->addItem(RoomG);

    RoomH->setRect(0,0,10,10);
    RoomH->setZValue(5);
    this->addItem(RoomH);

    RoomI->setRect(0,20,10,10);
    RoomI->setZValue(5);
    this->addItem(RoomI);

    RoomJ->setRect(0,30,10,10);
    RoomJ->setZValue(5);
    this->addItem(RoomJ);

    if(currentRoom->getDescription()=="a")
        RoomA->setBrush(Qt::green);
    else if(currentRoom->getDescription()=="b")
        RoomB->setBrush(Qt::green);
    else if(currentRoom->getDescription()=="c")
        RoomC->setBrush(Qt::green);
    else if(currentRoom->getDescription()=="d")
        RoomD->setBrush(Qt::green);
    else if(currentRoom->getDescription()=="e")
        RoomE->setBrush(Qt::green);
    else if(currentRoom->getDescription()=="f")
        RoomF->setBrush(Qt::green);
    else if(currentRoom->getDescription()=="g")
        RoomG->setBrush(Qt::green);
    else if(currentRoom->getDescription()=="h")
        RoomH->setBrush(Qt::green);
    else if(currentRoom->getDescription()=="i")
        RoomI->setBrush(Qt::green);
    else if(currentRoom->getDescription()=="j")
        RoomJ->setBrush(Qt::green);
}

void Background:: createInventoryBox(QString inventoryString){
    inventoryEditor = new QTextEdit;
    inventoryEditor->move(400,475);
    inventoryEditor->setReadOnly(true);
    inventoryContString += "Inventory";
    inventoryEditor->setPlainText(inventoryContString);
    this->addWidget(inventoryEditor);
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

    this->addItem(vampire);
    this->addItem(dragon);
    this->addItem(rect);


    if(currentRoom->itemInRoom()){
        item=currentRoom->item;
        item->setVisible(true);
        this->addItem(item);
        qDebug()<<"kjdbasihg";
        qDebug()<<item->getDescription();
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
    RoomA->setBrush(Qt::white);
    RoomB->setBrush(Qt::white);
    RoomC->setBrush(Qt::white);
    RoomD->setBrush(Qt::white);
    RoomE->setBrush(Qt::white);
    RoomF->setBrush(Qt::white);
    RoomG->setBrush(Qt::white);
    RoomH->setBrush(Qt::white);
    RoomI->setBrush(Qt::white);
    RoomJ->setBrush(Qt::white);

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


    if(currentRoom->itemInRoom()==true && item){
        this->removeItem(item);
    }

    addText();

    vampire->resetHealth();
    dragon->resetHealth();

    delete timer;
}

void Background::keyPressEvent(QKeyEvent *event)
{
    if(currentRoom->monsterInRoom()){
        if(event->key()==Qt::Key_X)
        {
                if(vampire->scenePos()==QPointF(470,200)){
                    player->setDamage(10);
                    vampire->decreaseHealthByAttack(10);
                    vampire->setPixmap(QPixmap(":/Images/vampireAttacked.png"));
                    vampire->z=1;
                    int x=player->getDamage();
                    qDebug()<<x<<"damage";
                }

        }
    }
    else if(currentRoom->bossInRoom()){
        if(event->key()==Qt::Key_X)
        {
                if(dragon->scenePos()==QPointF(470,200)){
                    dragon->decreaseHealthByAttack(player->getDamage());
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
                item->setVisible(false);
                currentRoom->setItem(false);
                inventoryContString = item->getDescription();
                qDebug()<<inventoryContString;
                inventoryEditor->setPlainText(inventoryContString);
            }

    }

    if(event->key()==Qt::Key_D)
    {
        if(currentRoom->itemInRoom()==false){
            itemsInInventory=player->getInventory()->getInventoryList();
            itemToDrop=itemsInInventory.back();
            itemsInInventory.pop_back();
            currentRoom->addItem(itemToDrop);
            currentRoom->setItem(true);
            refreshScene();
        }
    }
}






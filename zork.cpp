#include "zork.h"
#include "player.h"
#include <QImage>
#include <QGraphicsPixmapItem>

Zork::Zork(QWidget *parent)
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    createMonster();
    createPrincess();
    createBoss();
    currentRoom=createRooms();
    createExits();
}

Zork::~Zork()
{
    delete player;
}

Player* Zork::play(){
    player = new Player();
    player->setDamage(25);
    return player;

}

void Zork::createMonster(){
    vampire = new Monster();
}

void Zork::createPrincess()
{
    princess = new Princess();
}

void Zork::createBoss(){
    dragon = new Boss();
}

Room * Zork::createRooms(){

    a= new Room("a");

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
    key=new Key("Rusty Key",20);

    g= new Room("g");
    h= new Room("h");
    i= new Room("i");
    j= new Room("j");

    return j;

}

void Zork::createExits(){

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
    f->setBoss(true);

    g->setExits(NULL, NULL, NULL, f);
    g->setPrincess(true);
    g->setCanEnter(false);

    h->setExits(NULL, f, NULL, NULL);

    i->setExits(NULL, d, j, NULL);
    i->setMonster(true);

    j->setExits(i, NULL, NULL, NULL);
}


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
    delete vampire;
    delete dragon;
    delete princess;
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete f;
    delete g;
    delete h;
    delete i;
    delete j;
    delete key;
    delete teleporter;
    delete potion;
    delete weapon;
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
    teleporter=new Teleporter("Teleporter",50);
    d->addItem(teleporter);
    d->setItem(true);

    e= new Room("e");
    f= new Room("f");
    key=new Key("Rusty Key",20);

    g= new Room("g");
    h= new Room("h");
    i= new Room("i");
    j= new Room("j");

    rooms+=a;
    rooms+=b;
    rooms+=c;
    rooms+=d;
    rooms+=e;
    rooms+=f;
    rooms+=g;
    rooms+=h;
    rooms+=i;
    rooms+=j;

    return j;
}

void Zork::createExits(){

    //         (N, E, S, W)
    a->setExits(f, b, d, c);
    a->setMonster(true);

    b->setExits(NULL, NULL, NULL, a);
    b->setMonster(true);

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


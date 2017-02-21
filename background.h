#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsRectItem>
#include "monster.h"
#include "room.h"
#include "mytimer.h"
#include "buttonaction.h"
#include "player.h"
#include "attack.h"
#include <QtCore>
#include <string>

class Background : public QGraphicsScene
{
    Q_OBJECT
public:
    QGraphicsRectItem *rect;
    explicit Background();
    Monster * vampire;
  // Player * play;
    Room *currentRoom;
    Room * nextRoom;
    int delB1=0;
    int delB2=0;
    int delB3=0;
    int delB4=0;
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;
    QPushButton * button1;
    QPushButton * button2;
    QPushButton * button3;
    QPushButton * button4;
    MyTimer * timer;
    void createRooms();
    void setScene(string direction);
    void createExits();
    void setRoomExits(Room * r);
    void createRect();
    void createMonster();
    void addToScene();
    void addAttacked(Attack * item);
    //on_button1_clicked();

public slots:
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button4_clicked();

};

#endif // BACKGROUND_H

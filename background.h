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
#include "boss.h"
#include "attack.h"
#include <QtCore>
#include <string>
#include <QTextEdit>
#include "character.h"

class Background : public QGraphicsScene
{
    Q_OBJECT
public:
    string inventoryContString;
    explicit Background(Player * play);
    void setScene(string direction);
    void createExits();
    void setRoomExits(Room * r);
    void createRect();
    void createMonster();
    void createBoss();
    void createTextBox();
    void addToScene();
    void clearBackground();
    void addText();
    void createInventoryBox(string inventoryString);
    Room * createRooms();
    void keyPressEvent(QKeyEvent *event);

public slots:
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button4_clicked();

private:
    QGraphicsRectItem *rect;
    Monster* vampire;
    Boss * dragon;
    string inventoryString;
    QTextEdit * smallEditor;
    QTextEdit * inventoryEditor;
    Room *currentRoom;
    Room * nextRoom;
    Player * player;
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
};

#endif // BACKGROUND_H

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsRectItem>
#include "monster.h"
#include "room.h"
#include "mytimer.h"
#include "item.h"
#include "player.h"
#include "boss.h"
#include "princess.h"
#include "key.h"
#include "weapon.h"
#include "teleporter.h"
#include "potion.h"
#include <QtCore>
#include <string>
#include <QTextEdit>
#include "character.h"
#include <vector>
#include <QComboBox>
#include "myvector.h"
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QDebug>
#include <QObject>
#include "zork.h"
#include <QMessageBox>

class Background : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Background(Zork* zork);
    ~Background();
    void setScene(const string direction);
    inline void refreshScene();
    void setRoomExits(Room * r);
    void createCave();
    void createTextBox();
    void createMapGUI();
    inline void addToScene();
    inline void clearBackground();
    void addText();
    void inventoryBox();
    void controlsBox();
    void keyPressEvent(QKeyEvent *event);

    int delB5=0;
public slots:
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button4_clicked();
    void on_button5_clicked();


private:
    QMessageBox msgBox;
    QString inventoryContString;
    Zork* zork1;
    QGraphicsPixmapItem *cave;
    QString inventoryString;
    QTextEdit * smallEditor;
    QTextEdit * inventoryEditor;
    Room * nextRoom;
    Player * player;
    int delB1=0;
    int delB2=0;
    int delB3=0;
    int delB4=0;
    QPushButton * button1;
    QPushButton * button2;
    QPushButton * button3;
    QPushButton * button4;
    QPushButton * button5;
    MyTimer * timer;
    Inventory * inventory;
    Item * item;
    Item * itemToDrop;
    vector<Item*> itemsInInventory;
    myVector<QString> controls;
    QGraphicsRectItem *RoomA,*RoomB,*RoomC,*RoomD,*RoomE,*RoomF,*RoomG,*RoomH,*RoomI,*RoomJ;
    QComboBox *inventoryComboBox;
    QComboBox *controlsComboBox;
};

#endif // BACKGROUND_H

#include "zork.h"
#include <QImage>
#include <QGraphicsPixmapItem>

Zork::Zork(QWidget *parent)
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    backg = new Background();
    play = new Player();
   // backg->createRect();
  //  backg->createMonster();
  //  backg->addToScene();
   // backg->setScene();

    setScene(backg);
    show();
}

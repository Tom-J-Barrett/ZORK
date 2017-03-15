#include <QApplication>
#include <QGraphicsScene>
#include "zork.h"
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QMainWindow>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Zork *zork1=new Zork();
    zork1->show();

    return app.exec();
}

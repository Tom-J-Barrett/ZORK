#include <QApplication>
#include <QGraphicsScene>
#include "zork.h"
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QMainWindow>
#include <QDebug>
#include "background.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Zork *zork1=new Zork();
    Background *bg = new Background(zork1);
    zork1->setScene(bg);
    zork1->show();
    zork1->setAttribute(Qt::WA_DeleteOnClose);
    return app.exec();
}

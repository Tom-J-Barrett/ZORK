#include <QApplication>
#include <QGraphicsScene>
#include "zork.h"
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QMainWindow>
#include <QDebug>
#include "background.h"

template<class FIRST, class SECOND>
FIRST smaller(FIRST a, SECOND b){
    qDebug()<<"Template";
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Zork *zork1=new Zork();
    Background *bg = new Background(zork1);
    zork1->setScene(bg);
    zork1->show();
    return app.exec();
}

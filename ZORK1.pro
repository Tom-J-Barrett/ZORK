#-------------------------------------------------
#
# Project created by QtCreator 2017-02-04T14:19:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZORK1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp \
    zork.cpp \
    room.cpp \
    character.cpp \
    monster.cpp \
    boss.cpp \
    player.cpp \
    princess.cpp \
    item.cpp \
    weapon.cpp \
    potion.cpp \
    key.cpp \
    background.cpp \
    buttonaction.cpp \
    mytimer.cpp \
    attack.cpp \
    inventory.cpp \
    treasure.cpp \
    myvector.cpp

HEADERS  += \
    boss.h \
    background.h \
    character.h \
    item.h \
    key.h \
    monster.h \
    player.h \
    potion.h \
    princess.h \
    room.h \
    weapon.h \
    zork.h \
    buttonaction.h \
    mytimer.h \
    attack.h \
    inventory.h \
    treasure.h \
    myvector.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc

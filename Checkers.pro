TEMPLATE = app
QT += widgets
CONFIG += console c++14
CONFIG -= app_bundle


SOURCES += main.cpp \
    point.cpp \
    cell.cpp \
    pointtest.cpp \
    board.cpp \
    celltest.cpp \
    boardtest.cpp \
    man.cpp \
    checkers.cpp \
    player.cpp \
    iaplayer.cpp \
    checkerstest.cpp \
    view/menu.cpp \
    view/manview.cpp \
    view/viewutilities.cpp \
    view/cellview.cpp

HEADERS += \
    point.h \
    cell.h \
    catch.h \
    board.h \
    man.h \
    checkers.h \
    player.h \
    iaplayer.h \
    color.h \
    view/menu.h \
    view/manview.h \
    view/viewutilities.h \
    view/cellview.h

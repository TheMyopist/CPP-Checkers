TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    point.cpp \
    cell.cpp \
    pointtest.cpp \
    board.cpp \
    celltest.cpp \
    boardtest.cpp \
    man.cpp \
    checkers.cpp \
    player.cpp

HEADERS += \
    point.h \
    cell.h \
    catch.h \
    board.h \
    man.h \
    checkers.h \
    player.h

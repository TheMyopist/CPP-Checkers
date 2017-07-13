TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    point.cpp \
    cell.cpp \
    pointtest.cpp \
    board.cpp

HEADERS += \
    point.h \
    cell.h \
    catch.h \
    board.h

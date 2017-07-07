TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    point.cpp \
    cell.cpp \
    pointtest.cpp

HEADERS += \
    point.h \
    cell.h \
    catch.h

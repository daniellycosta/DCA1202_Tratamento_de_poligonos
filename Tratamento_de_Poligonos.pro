TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    retangulo.cpp \
    poligono.cpp \
    ponto.cpp

HEADERS += \
    point.h \
    polygon.h \
    rectangle.h

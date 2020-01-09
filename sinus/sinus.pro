TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++17

CONFIG += link_pkgconfig
PKGCONFIG += opencv

SOURCES += sinus.cpp

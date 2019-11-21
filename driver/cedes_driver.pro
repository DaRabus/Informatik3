TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++17

SOURCES += main.cpp \
    serial.cpp \
    crc16.cpp \
    sensor_constants.cpp \
    packet.cpp \
    sensor.cpp

HEADERS += \
    serial.h \
    crc16.h \
    sensor_constants.h \
    packet.h \
    sensor.h

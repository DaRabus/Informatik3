TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++17
LIBS += -lncurses

SOURCES += main.cpp \
    maze.cpp \
    intvec2.cpp \
    agent.cpp \
    tremaux.cpp \
    mapping_agent.cpp \
    pose.cpp \
    random_mouse.cpp \
    wall_follower.cpp \
    console_screen.cpp

HEADERS += \
    field_type.h \
    maze.h \
    console_screen.h \
    agent.h \
    mapping_agent.h \
    tremaux.h \
    pose.h \
    random_mouse.h \
    wall_follower.h \
    intvec2.h \
    screen.h

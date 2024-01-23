TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -pedantic-errors\
                  -std=c++17\
                  -Wall\
                  -Wuninitialized

SOURCES += \
        controller/Controller.cpp \
        main.cpp \
        model/Board.cpp \
        model/Game.cpp \
        model/Hexagon.cpp \
        model/Marble.cpp \
        model/Move.cpp \
        model/Player.cpp \
        model/Position.cpp \
        model/dp/Subject.cpp \
        test/modelTest.cpp \
        view/View.cpp

HEADERS += \
    controller/Controller.h \
    model/Board.h \
    model/Direction.h \
    model/Game.h \
    model/Hexagon.h \
    model/Marble.h \
    model/Model.h \
    model/Move.h \
    model/Player.h \
    model/PlayerColor.h \
    model/Position.h \
    model/dp/Observer.h \
    model/dp/Subject.h \
    test/catch.hpp \
    view/View.h

FORMS += \
    dialog.ui

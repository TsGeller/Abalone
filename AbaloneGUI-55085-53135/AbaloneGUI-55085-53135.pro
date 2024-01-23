QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += console c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller/Controller.cpp \
    controller/controllergui.cpp \
    gui/hexacell.cpp \
    gui/mainwindow.cpp \
    main.cpp \
    model/Board.cpp \
    model/Game.cpp \
    model/Hexagon.cpp \
    model/Marble.cpp \
    model/Move.cpp \
    model/Player.cpp \
    model/Position.cpp \
    model/dp/Subject.cpp \
    #test/modelTest.cpp \
    view/View.cpp

HEADERS += \
    controller/Controller.h \
    controller/controllergui.h \
    gui/hexacell.h \
    gui/mainwindow.h \
    gui/point.h \
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
    #test/catch.hpp \
    view/View.h

FORMS += \
    gui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

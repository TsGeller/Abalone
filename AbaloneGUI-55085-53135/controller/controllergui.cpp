#include "controllergui.h"

using namespace std;

ControllerGUI::ControllerGUI(Game * observable):
    _observable(observable)
{
    _mainWindow = new MainWindow(nullptr, _observable);
}

void ControllerGUI::initialise()
{
    _observable->initialise();
    _mainWindow->update(_observable);
}

MainWindow * ControllerGUI::getMainWindow()
{
    return _mainWindow;
}

void ControllerGUI::startGame()
{
    bool gameIsOver = _observable->isOver();
}



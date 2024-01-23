/**
 *\file controllergui.h
 *\brief Class controllergui of Abalone
 *\author Jan Schumacher Vincke - Thomas Geller
 *\version GUI
 *\date 05/05/2020
 */
#ifndef CONTROLLERGUI_H
#define CONTROLLERGUI_H

#include "../model/Game.h"
#include "../gui/mainwindow.h"
/**
 * @brief The ControllerGUI class class of controller gui
 */
class ControllerGUI
{
  private:

    Game  * _observable;/*!< attributes Game*/
    MainWindow * _mainWindow;/*!< attributes MainWindow*/

  public:

    /**
    * A constructor.
    * Constructor for the class controllerGUI
    */
    ControllerGUI(Game *);
    /**
     * @brief getMainWindow; simple getter of mainWindow
     * @return the mainWindow
     */
    MainWindow  * getMainWindow();

    /**
     * Initialise the game with marble on the board
     */
    void initialise();

    /**
    * method startGame,
    * the method gives the instructions for the conduct of the game
    */
    void startGame();


};


#endif // CONTROLLERGUI_H

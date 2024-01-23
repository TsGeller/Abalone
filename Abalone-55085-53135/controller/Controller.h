/**
 *\file Controller.h
 *\brief Class controller of Abalone
 *\author Jan Schumacher Vincke - Thomas Geller
 *\version Console
 *\date 02/04/2020
 */
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/Game.h"
#include "../view/View.h"
/**
 * \brief Class controller
 */
class Controller
{
  private:
    Game  * game_;/*!< attributes Game*/
    View view_;/*!< attribute view*/
  public:
    /**
    * A constructor.
    * Constructor for the class controller
    */
    Controller(Game *, View);
    /**
     * Initialise the game with marble on the board
     */
    void initialise();
    /**
    * method startGame,
    * the method gives the instructions for the conduct of the game
    */
    void startGame();
  private:
    /**
     * @brief loopGame
     * display the board of the game and loop the game while this is not finish
     */
    void loopGame(bool);
    /**
     * @brief checkAnswer check different param enter in input
     * @param arrayCommand
     * @return true if its a real command
     */
    bool checkAnswer(std::vector<std::string> arrayCommand);
    /**
     * @brief checkAnswerPlay indicates to the game the move
     * @param arrayCommand
     */
    void checkAnswerPlay(std::vector<std::string> arrayCommand);
    /**
     * @brief takeMarbles put marble of the command and return list of different marbles
     * @param position position of marbles
     * @return list of marbles
     */
    std::list<std::string> takeMarbles(std::string position);
    /**
     * @brief tabCommand split the command in input and put in a array
     * @param command the string to split
     * @return array of split command
     */
    std::vector<std::string> tabCommand(std::string command);
};

#endif // CONTROLLER_H

/**
 * \file View.h
 * @brief Class View of Abalone
 * @author Jan Schumacher Vincke - Thomas Geller
 * @version Console
 * @date 02/04/2020
 */
#ifndef VIEW_H
#define VIEW_H
#include "../model/dp/Observer.h"
#include "../model/dp/Subject.h"
#include "../model/Player.h"
#include "../model/Board.h"
#include "../model/Hexagon.h"
#include "../model/Game.h"

#include <iostream>
/**
 * \brief Class View
 */
class View : public nvs::Observer
{
  private:
    Game * subject_;/*!< Subject position*/
  public:
    /**
     * @brief View simple Constructor of view with attribute Game
     */
    View(Game *);
    /**
     * @brief update
     */
    virtual void update(const nvs::Subject *) override;
    /**
     * @brief initialise initialise the game
     */
    void initialise();
    /**
     * @brief quit display a message to ask if the player have a question with options
     */
    void quit();
    /**
     * @brief displayHelp display a message to ask if the player have a question with options
     */
    void displayHelp();
    /**
     * @brief askCommand Display a message to enter the command
     * @return the comand ask by the user
     */
    std::string askCommand();
    /**
     * @brief theScore display the score of the player
     */
    void theScore();
    /**
     * @brief displayWinner display the winner
     * @param player the player
     */
    void displayWinner(Player player);
    /**
    *@brief displayBoard display the board of the game
    * @param board the board
    */
    void displayBoard(Board &);
    /**
     * @brief printImpossibleMovement display a message to say impossible movement
     */
    void printImpossibleMovement();
    /**
     * @brief printCurrentPlayer current player displayed
     */
    void printCurrentPlayer(Player);
    /**
     * @brief printWrongCommand display a message to say wrong command
     */
    void printWrongCommand();
  private:
    /**
     * @brief separationView make the seoaration bettween different round
     * @param length length of -
     */
    void separationView(unsigned length);
    /**
     * @brief printTypeMarble print the type of marble
     * @param board the board
     * @param pos position of marble
     */
    void printTypeMarble(Board & board, Position pos);
    /**
     * @brief colorName return color name
     * @returnname of color
     */
    std::string colorName(PlayerColor);
};

#endif // VIEW_H


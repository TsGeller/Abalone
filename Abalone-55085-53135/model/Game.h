/**
 * \file Game.h
 * @brief Class Game of Abalone
 * @author Jan Schumacher Vincke - Thomas Geller
 * @version Console
 * @date 02/04/2020
 */
#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include "Model.h"
#include "Move.h"
#include "dp/Subject.h"

#include <stdbool.h>
#include <vector>
#include <list>
#include <string>

/**
* \brief Class Game , its the principal class to build the game
* \brief Assemble all the elements of the game.
*/
class Game : public Model, public nvs::Subject
{
  private:
    Board board_;/*!< Represents board */
    Player current_;/*!<Represents the current player */
    Player opponent_; /*!<Represents the opponent player*/
  public:
    /**
     * @brief Game,Builder of the Game object. It creates the board and the 2 players.
     */
    Game();
    /**
     * @brief getBoard, simple getter of board
     * @return board
     */
    Board & getBoard();
    /**
     * @brief getCurrent, simple getter of current player
     * @return Player current
     */
    Player & getCurrent();
    /**
     * @brief getOpponent, simple getter of opponent player
     * @return Player opponent
     */
    Player & getOpponent();
    /**
     * @brief initialise, initialise the game with marble on the board
     */
    void initialise();
    /**
     * @brief start, start the game , and check if there is a board
     */
    void start();
    /**
     * @brief isOver make the movement on the board ask by the player
     * @return Returns true if the game is over otherwise returns false.
     */
    bool isOver();
    /**
    * @brief make the movement on the board ask by the player
    */
    void play(std::vector<std::string>);
    /**
     * @brief score, get the score of the player
     * @param player  the player in question
     * @return the score of the player
     */
    unsigned score(Player player);
    /**
    * @brief getWinner, get the winner of the game
    * @return the winner
    */
    Player getWinner();
  private:
    /**
    * @brief swapPlayer, Allows to pass the turn of the current player.
    * The current player becomes the opponent and the opponent becomes the current player.
    */
    void swapPlayer();
    /**
     * @brief posCurrentColor chek if the marble choice is the same that the color of player
     */
    void posCurrentColor(Position);
    /**
     * @brief checkMovePossible check if the move is possible
     */
    void checkMovePossible(Move, bool, bool, bool, unsigned, unsigned);
    /**
     * @brief applyMove make the movement qhen its possible
     */
    void applyMove(Move);
    /**
     * @brief removePlayerMarble remove the marble of the player
     */
    void removePlayerMarble(PlayerColor);
    /**
     * @brief stringToPosition , String to convert in a Position
     * @return the position convert
     */
    Position stringToPosition(std::string);
    /**
     * @brief verifyDirection check the direction with the different retracted positions
     * @return the direction matched
     */
    Direction verifyDirection(Position, std::string);
    /**
     * @brief lineMovement manage online travel
     */
    void lineMovement(std::vector<std::string>);
    /**
     * @brief diagonalMovement initialise the diagonal movement
     */
    void diagonalMovement(std::vector<std::string>);
    /**
     * @brief marblesInDiagonal give marble in dagional with the string given
     * @return the position of different marble
     */
    std::list<Position> marblesInDiagonal(Position, Position);
    /**
     * @brief verifyDiagonalLine verify if the position are in the same line
     */
    void verifyDiagonalLine(std::list<Position>);
    /**
     * @brief verifyDiagonalMove verify if the next position is free
     */
    void verifyDiagonalMove(Move);
    /**
     * @brief giveDirection return the direction with position given
     * @return direction matched to position
     */
    Direction giveDirection(Position, Position);
    /**
     * @brief traductionRow with a char , return the position convert
     * @param row a row
     * @return return a integer convert
     */
    int traductionRow(char row);
};
#endif // GAME_H

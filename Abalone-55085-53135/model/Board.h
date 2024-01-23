/**
 * \file Board.h
 * @brief Class Board of Abalone
 * @author Jan Schumacher Vincke - Thomas Geller
 * @version Console
 * @date 02/04/2020
 */
#ifndef BOARD_H
#define BOARD_H
#define SIZE 9
#include "Hexagon.h"
#include "Position.h"
#include <stdbool.h>
#include <vector>
#include <optional>

/**
* \brief Board Class of the game
*/
class Board
{
  private:
    std::vector<std::vector<Hexagon>>
                                   hexagons_;/*!<Represents the game board, it is a 2D array of hexagons. */
  public:
    /**
    * Constructor of the Board object. It will create a 9 by 9 2D board.
    */
    Board();
    /**
     * @brief getHexagons,Returns the 2D array of hexagons.
     * @return  array of hexagons
     */
    std::vector<std::vector<Hexagon>> & getHexagons();
    /**
    * @brief isInside, Check if the hexagons are in the game board.
    *  Taking care that some hexagons are not in the game board.
    * @param position position to check
    * @return Returns true if the hexagon is in the game board otherwise returns false.
    */
    bool isInside(Position) const;
    /**
    * @brief getHexagon
    * Returns the hexagon at the position given in parameter.
    * @param position position on the board
    * @return the hexagon at the position
    */
    Hexagon & getHexagon(Position);
    /**
    * @brief isFree , Checks if the hexagon whose position is given in parameter has a ball or not.
    * @param position position on the board
    * @return Returns true if the hexagon is free otherwise false.
    */
    bool isFree(Position);
    /**
     * @brief hasColor check the equality between two color
     * @return true if its the same color false if not
     */
    bool hasColor(Position, PlayerColor);
    /**
    * @brief putMarble, Place the given marble on the hexagon at the given position on the board.
    * @param position position to check
    * @param marble the marble to put on the position
    */
    void putMarble(std::optional<Marble>, Position);
    /**
     * @brief getMarble , get the marble at the position position
     * @param position the position
     * @return reference of  marble if there is one
     */
    std::optional<Marble> & getMarble(Position position);
    /**
    * methode who remove the marble at the position
    * @param position position one the board
    */
    void removeMarble(Position);
    /**
    * methode who check egality
    * @param rhs to compare
    * @return true is its equals
    */
    bool operator==(const Board & rhs) const;
    /**
    * methode who check inegality
    * @param rhs to compare
    * @return true is its inequals
    */
    bool operator!=(const Board & rhs) const;
  private:
    /**
    * @brief isNotBanned check if the position is on the board,
    * the positions mentioned in the method are not on the board
    * @param position position to check
    * return true if its true and false if not
    */
    bool isNotBannedPos(Position) const;
};


#endif // BOARD_H

/**
 * \file Position.h
 * \brief Class Position of Abalone
 * \author Jan Schumacher Vincke - Thomas Geller
 * \version Console
 * \date 02/04/2020
 */
#ifndef POSITION_H
#define POSITION_H
#include "Direction.h"


/**
 * \brief Represents a position (row, column) in a table.
 */
class Position
{
  private:
    int row_;/*!< row position*/
    int column_;/*!< column of position*/
  public:
    /**
     * @brief Position simple constructor of position
     * @param row
     * @param column
     */
    Position(int row, int column);
    /**
     * @brief getRow simple getter of row
     * @return integer
     */
    int & getRow();
    /**
     * @brief getColumn simple getter of column
     * @return column
     */
    int & getColumn();
    /**
    * @brief next Returns the next position in a direction given in parameter.
    * @param direction_ the direction
    * @return the position
    */
    Position next(Direction direction_);
    /**
    * methode who check egality
    * @param rhs to compare
    * @return true is its equals
    */
    bool operator==(const Position & rhs) const;
    /**
    * methode who check inegality
    * @param rhs to compare
    * @return true is its inequals
    */
    bool operator!=(const Position & rhs) const;
};
#endif // POSITION_H

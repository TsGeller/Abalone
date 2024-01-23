/**
 * \file Move.h
 * @brief Class Move of Abalone
 * @author Jan Schumacher Vincke - Thomas Geller
 * @version Console
 * @date 02/04/2020
 */
#ifndef MOVE_H
#define MOVE_H

#include "Position.h"
#include "Direction.h"
#include <list>
#include <iostream>
/**
 * \brief Represents the movement of one or more balls.
 */
class Move
{
  private:
    std::list<Position>
    positions_;/*!< list of position of marble to move*/
    Direction direction_;/*!< direction in wich marble are moved */
  public:
    /**
    * @brief constructor of move
    * @param listPosition_ list of position
    * @param direction_ direction of movement
    */
    Move(std::list<Position>listPosition_, Direction direction_);
    /**
     * @brief getPositions, simple getter  list of position
     * @return list of positions
     */
    std::list<Position> & getPositions();
    /**
     * @brief getDirection simple getter of  direction
     * @return Direction
     */
    Direction & getDirection();
};
#endif // MOVE_H

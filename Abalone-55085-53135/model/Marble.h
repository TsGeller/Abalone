/**
 * \file Marble.h
 * @brief Class Marble of Abalone
 * @author Jan Schumacher Vincke - Thomas Geller
 * @version Console
 * @date 02/04/2020
 */
#ifndef MARBLE_H
#define MARBLE_H
#include "PlayerColor.h"

/**
 * \brief Represents a ball on the board.
 * \brief It has a color that is either white or black.
 */
class Marble
{
  private:
    PlayerColor color_; /*!< the color of the marble */
  public:
    /**
    * @brief Marble simple constructor of marble with color
    * @param color of the marble
    */
    Marble(PlayerColor);
    /**
     * @brief getColor simple getter color
     * @return color
     */
    PlayerColor & getColor();
    /**
    * @brief methode who check egality
    * @param rhs to compare
    * @return true is its equals
    */
    bool operator==(const Marble & rhs) const;
    /**
    * @brief methode who check inegality
    * @param rhs to compare
    * @return true is its inequals
    */
    bool operator!=(const Marble & rhs) const;
};
#endif // MARBLE_H

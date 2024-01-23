/**
 * \file Hexagon.h
 * @brief Class Hexagon of Abalone
 * @author Jan Schumacher Vincke - Thomas Geller
 * @version Console
 * @date 02/04/2020
 */
#ifndef HEXAGONE_H
#define HEXAGONE_H
#include <stdbool.h>
#include <optional>

#include "Marble.h"

/**
* \brief Represents a hexagon on the game board. A hexagon may or may not have a marble.
*/
class Hexagon
{
  private:
    std::optional<Marble> marble_;/*!< an optionnal marble */
  public:
    /**
    * Constructor of hexagon
    * @param marble optionnal marble
    */
    Hexagon(std::optional<Marble> marble = std::nullopt);
    /**
    * @brief getMarble simple getter of marble
    * @return marble
    */
    std::optional<Marble> & getMarble();
    /**
    * @brief putMarble put marble on the hexagon
    * @return the marble to put on the hexagon
    */
    void putMarble(std::optional<Marble>);
    /**
     * @brief removeMarble , remove the marble on the hexagon
     */
    void removeMarble();
    /**
     * @brief isFree check if the hexagon is free
     * @return free if its free , false if not
     */
    bool isFree() const;
    /**
     * @brief hasColor Checks if the ball has the color of the color in parameter.
     * @return Returns true if it has the same color otherwise false.
     */
    bool hasColor(PlayerColor);
    /**
    * methode who check egality
    * @param rhs to compare
    * @return true is its equals
    */
    bool operator==(const Hexagon & rhs) const;
    /**
    * methode who check egality
    * @param rhs to compare
    * @return true is its inequals
    */
    bool operator!=(const Hexagon & rhs) const;
};
#endif // HEXAGONE_H

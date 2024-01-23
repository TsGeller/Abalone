/**
 * \file Player.h
 * @brief Class Player of Abalone
 * @author Jan Schumacher Vincke - Thomas Geller
 * @version Console
 * @date 02/04/2020
 */
#ifndef PLAYER_H
#define PLAYER_H



#include "PlayerColor.h"
/**
 * \brief  Player Represents a player it takes in parameter a color (associated with the color of his ball) and a number of pieces (Marble)
 */
class Player
{
  private:
    PlayerColor color_;/*!< color of the player*/
    unsigned nbrMarble_;/*!< number of marble per player*/
  public:
    /**
    *simple constructor of player
    */
    Player(PlayerColor, unsigned nbrMarble = 14);
    /**
     * @brief getPlayerColor simple getter of color player
     * @return color
     */
    PlayerColor & getPlayerColor();
    /**
     * @brief getNbrMarble get number of marble
     * @return a unsigned
     */
    unsigned & getNbrMarble();
    /**
     * @brief removeMarble just decrement number of marble
     */
    void removeMarble();
    /**
    * methode who check egality
    * @param rhs to compare
    * @return true is its equals
    */
    bool operator==(const Player & rhs) const;
    /**
    * methode who check inegality
    * @param rhs to compare
    * @return true is its inequals
    */
    bool operator!=(const Player & rhs) const;
};
#endif // PLAYER_H

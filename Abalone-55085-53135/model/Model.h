/**
 * \file Model.h
 * @brief interface Model of Abalone
 * @author Jan Schumacher Vincke - Thomas Geller
 * @version Console
 * @date 02/04/2020
 */
#ifndef MODEL_H
#define MODEL_H

#include "Board.h"
#include "Player.h"
#include "Move.h"

#include <stdbool.h>
#include <vector>
#include <string>
/**
 * @brief The Model  interface of class game
 */
class Model
{
  public :
    virtual Board & getBoard() = 0;
    virtual Player & getCurrent() = 0;
    virtual Player & getOpponent() = 0;
    virtual void initialise() = 0;
    virtual void start() = 0;
    virtual bool isOver() = 0;
    virtual void play(std::vector<std::string>) = 0;
    virtual unsigned score(Player) = 0;
    virtual Player getWinner() = 0;
  private:
    virtual void swapPlayer() = 0;
};
#endif // MODEL_H

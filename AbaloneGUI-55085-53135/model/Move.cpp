#include "Move.h"

Move::Move(std::list<Position> positions,
           Direction direction): positions_(positions), direction_(direction) {}

std::list<Position> & Move::getPositions()
{
    return positions_;
}

Direction & Move::getDirection()
{
    return direction_;
}

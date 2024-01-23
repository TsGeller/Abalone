#include "Board.h"

#include <list>
#include <stdexcept>

Board::Board()
{
    hexagons_ = std::vector<std::vector<Hexagon>> (SIZE,
                std::vector<Hexagon>(SIZE, Hexagon()));
}

std::vector<std::vector<Hexagon>> & Board::getHexagons()
{
    return hexagons_;
}

bool Board::isInside(Position position) const
{
    bool inside{false};
    if (position.getRow() < SIZE  && position.getRow() >= 0
            && position.getColumn() < SIZE && position.getColumn() >= 0)
    {
        inside = true;
    }
    if (inside)
    {
        inside = isNotBannedPos(position);
    }

    return inside;
}

Hexagon & Board::getHexagon(Position position)
{
    if (!isInside(position))
    {
        throw std::logic_error("Board.getHexagon(), the position is out of the board !");
    }
    return hexagons_[position.getRow()][position.getColumn()];
}

bool Board::isFree(Position position)
{
    return getHexagon(position).isFree();
}

bool Board::hasColor(Position pos, PlayerColor color)
{
    return getHexagon(pos).hasColor(color);
}

void Board::putMarble(std::optional<Marble> marble, Position position)
{
    if (!isInside(position))
    {
        throw std::logic_error("Board.putMarble(), the position is out of the board !");
    }
    if (!isFree(position))
    {
        throw std::logic_error("Board.putMarble(), the position is not free !");
    }
    getHexagon(position).putMarble(marble);
}

std::optional<Marble> & Board::getMarble(Position position)
{
    return getHexagon(position).getMarble();
}

void Board::removeMarble(Position position)
{
    if (!isInside(position))
    {
        throw std::logic_error("Board.removeMarble(), the position is out of the board !");
    }
    if (isFree(position))
    {
        throw std::logic_error("Board.removeMarble(), the position is free !");
    }
    return getHexagon(position).removeMarble();
}

bool Board::isNotBannedPos(Position position) const
{
    std::list<Position> listPositionOut = { Position(1, 6), Position(1, 7), Position(1, 8), Position(9, 1), Position(2, 7), Position(2, 8)
                                            , Position(2, 9), Position(3, 8), Position(3, 9), Position(4, 9), Position(7, 1), Position(7, 1)
                                            , Position(6, 1), Position(7, 1), Position(8, 1), Position(9, 1), Position(7, 2), Position(8, 2)
                                            , Position(9, 2), Position(8, 3), Position(9, 3), Position(9, 4)
                                          };
    for (Position position_ : listPositionOut)
    {
        if (position == position_)
        {
            return false;
        }
    }
    return true;
}

bool Board::operator==(const Board & rhs) const
{
    return hexagons_ == rhs.hexagons_;
}

bool Board::operator!=(const Board & rhs) const
{
    return !operator==(rhs);
}

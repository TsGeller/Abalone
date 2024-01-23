#include "Position.h"
#include "iostream"
#include "Direction.h"


Position::Position(int row, int column): row_(row),
    column_(column) {}

int & Position::getRow()
{
    return row_;
}

int & Position::getColumn()
{
    return column_;
}

Position Position::next(Direction direction)
{
    switch (direction)
    {
        case Direction::NO :
            return Position(getRow() - 1, getColumn() - 1);
        case Direction::NE :
            return Position(getRow() - 1, getColumn());
        case Direction::O :
            return Position(getRow(), getColumn() - 1);
        case Direction::E :
            return Position(getRow(), getColumn() + 1);
        case Direction::SO :
            return Position(getRow() + 1, getColumn());
        case Direction::SE :
            return Position(getRow() + 1, getColumn() + 1);
    }

    return Position(0, 0);
}

bool Position::operator==(const Position & rhs) const
{
    return row_ == rhs.row_ && column_ == rhs.column_;
}

bool Position::operator!=(const Position & rhs) const
{
    return !operator==(rhs);
}

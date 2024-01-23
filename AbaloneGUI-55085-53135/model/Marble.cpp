#include "Marble.h"

Marble::Marble(PlayerColor color): color_(color) {}

PlayerColor & Marble::getColor()
{
    return color_;
}

bool Marble::operator==(const Marble & rhs) const
{
    return color_ == rhs.color_;
}

bool Marble::operator!=(const Marble & rhs) const
{
    return !operator==(rhs);
}

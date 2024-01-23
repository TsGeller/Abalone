#include "Hexagon.h"

#include <stdexcept>

Hexagon::Hexagon(std::optional<Marble> marble): marble_(
        marble) {}

std::optional<Marble> & Hexagon::getMarble()
{
    return marble_;
}

void Hexagon::putMarble(std::optional<Marble> marble)
{
    marble_ = marble;
}

void Hexagon::removeMarble()
{
    marble_.reset();
}

bool Hexagon::isFree() const
{
    return !marble_.has_value();
}

bool Hexagon::hasColor(PlayerColor color)
{
    return !isFree() && getMarble()->getColor() == color;
}

bool Hexagon::operator==(const Hexagon & rhs) const
{
    return marble_ == rhs.marble_;
}

bool Hexagon::operator!=(const Hexagon & rhs) const
{
    return !operator==(rhs);
}

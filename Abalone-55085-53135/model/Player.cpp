#include "Player.h"
#include "iostream"

Player::Player(PlayerColor color,
               unsigned nbrMarble): color_(color),
    nbrMarble_(nbrMarble) {}

PlayerColor & Player::getPlayerColor()
{
    return color_;
}

unsigned & Player::getNbrMarble()
{
    return nbrMarble_;
}

void Player::removeMarble()
{
    nbrMarble_--;
}

bool Player::operator==(const Player & rhs) const
{
    return color_ == rhs.color_ && nbrMarble_ == rhs.nbrMarble_;
}

bool Player::operator!=(const Player & rhs) const
{
    return !operator==(rhs);
}

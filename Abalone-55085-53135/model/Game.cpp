#include "Game.h"

#include <optional>

Game::Game(): board_{Board()}, current_{Player(PlayerColor::WHITE)}
    , opponent_{Player(PlayerColor::BLACK)} {}

Board & Game::getBoard()
{
    return board_;
}

Player & Game::getCurrent()
{
    return current_;
}

Player & Game::getOpponent()
{
    return opponent_;
}

void Game::initialise()
{
    getBoard().putMarble(Marble(PlayerColor::BLACK), Position(0, 0));
    getBoard().putMarble(Marble(PlayerColor::BLACK), Position(0, 1));
    getBoard().putMarble(Marble(PlayerColor::BLACK), Position(0, 2));
    getBoard().putMarble(Marble(PlayerColor::BLACK), Position(0, 3));
    getBoard().putMarble(Marble(PlayerColor::BLACK), Position(0, 4));
    getBoard().putMarble(Marble(PlayerColor::BLACK), Position(1, 0));
    getBoard().putMarble(Marble(PlayerColor::BLACK), Position(1, 1));
    getBoard().putMarble(Marble(PlayerColor::BLACK), Position(1, 2));
    getBoard().putMarble(Marble(PlayerColor::BLACK), Position(1, 3));
    getBoard().putMarble(Marble(PlayerColor::BLACK), Position(1, 4));
    getBoard().putMarble(Marble(PlayerColor::BLACK), Position(1, 5));
    getBoard().putMarble(Marble(PlayerColor::BLACK), Position(2, 2));
    getBoard().putMarble(Marble(PlayerColor::BLACK), Position(2, 3));
    getBoard().putMarble(Marble(PlayerColor::BLACK), Position(2, 4));

    getBoard().putMarble(Marble(PlayerColor::WHITE), Position(6, 4));
    getBoard().putMarble(Marble(PlayerColor::WHITE), Position(6, 5));
    getBoard().putMarble(Marble(PlayerColor::WHITE), Position(6, 6));
    getBoard().putMarble(Marble(PlayerColor::WHITE), Position(7, 3));
    getBoard().putMarble(Marble(PlayerColor::WHITE), Position(7, 4));
    getBoard().putMarble(Marble(PlayerColor::WHITE), Position(7, 5));
    getBoard().putMarble(Marble(PlayerColor::WHITE), Position(7, 6));
    getBoard().putMarble(Marble(PlayerColor::WHITE), Position(7, 7));
    getBoard().putMarble(Marble(PlayerColor::WHITE), Position(7, 8));
    getBoard().putMarble(Marble(PlayerColor::WHITE), Position(8, 4));
    getBoard().putMarble(Marble(PlayerColor::WHITE), Position(8, 5));
    getBoard().putMarble(Marble(PlayerColor::WHITE), Position(8, 6));
    getBoard().putMarble(Marble(PlayerColor::WHITE), Position(8, 7));
    getBoard().putMarble(Marble(PlayerColor::WHITE), Position(8, 8));
}

void Game::start()
{
    Board * ptBoard = & board_;
    if (ptBoard == NULL)
    {
        throw "Game.start(): The game don't have a board !";
    }
    if (isOver())
    {
        throw "Game.start(): The game is already over !";
    }
}

bool Game::isOver()
{
    return current_.getNbrMarble() < 9 || opponent_.getNbrMarble() < 9;
}

void Game::play(std::vector<std::string> arrayCommand)
{
    if (arrayCommand[1].length() == 4)
    {
        lineMovement(arrayCommand);
    }
    else if (arrayCommand[1].length() == 6)
    {
        diagonalMovement(arrayCommand);
    }
    else
    {
        throw std::logic_error("Game.play(), wrong commande !");
    }
    swapPlayer();
}

void Game::lineMovement(std::vector<std::string> arrayCommand)
{
    Position selected{stringToPosition(arrayCommand[1].substr(0, 2))};
    posCurrentColor(selected);
    Direction direction{verifyDirection(selected, arrayCommand[1].substr(2, 2))};
    unsigned nbrCurrentMarble{1};
    unsigned nbrOpponentMarble{0};
    Position posNext = selected.next(direction);
    std::list<Position> positions{selected};
    bool changeColor{false};
    bool outOrFree{false};
    bool pushOut{false};
    unsigned i{0};
    while (i < 6 && !outOrFree)
    {
        if (board_.isInside(posNext))
        {
            if (board_.hasColor(posNext, current_.getPlayerColor()))
            {
                nbrCurrentMarble++;
                positions.push_front(posNext);
            }
            else if (board_.hasColor(posNext, opponent_.getPlayerColor()))
            {
                changeColor = true;
                nbrOpponentMarble++;
                positions.push_front(posNext);
            }
            else
            {
                outOrFree = true;
                break;
            }
        }
        else
        {
            removePlayerMarble(board_.getMarble(positions.front())->getColor());
            board_.removeMarble(positions.front());
            positions.pop_front();
            pushOut = true;
            break;
        }
        posNext = posNext.next(direction);
        i++;
    }

    Move move{positions, direction};
    checkMovePossible(move, changeColor, outOrFree, pushOut,
                      nbrCurrentMarble,
                      nbrOpponentMarble);
}

void Game::diagonalMovement(std::vector<std::string> arrayCommand)
{
    Position posFirstMarble{stringToPosition(arrayCommand[1].substr(0, 2))};
    Position posLastMarble{stringToPosition(arrayCommand[1].substr(2, 2))};
    Direction direction{verifyDirection(posFirstMarble, arrayCommand[1].substr(4, 2))};
    std::list<Position> positions = marblesInDiagonal(posFirstMarble,
                                    posLastMarble);
    Move move{positions, direction};
    verifyDiagonalMove(move);
    applyMove(move);
}

std::list<Position> Game::marblesInDiagonal(Position posFirstMarble,
        Position posLastMarble)
{
    int row{(posFirstMarble.getRow() + posLastMarble.getRow()) / 2};
    int col{(posFirstMarble.getColumn() + posLastMarble.getColumn()) / 2};
    Position betweenPos{row, col};
    std::list<Position> positions{posFirstMarble};
    if (posFirstMarble != betweenPos && posLastMarble != betweenPos)
    {
        positions.push_front(betweenPos);
    }
    positions.push_front(posLastMarble);
    verifyDiagonalLine(positions);
    return positions;
}

void Game::verifyDiagonalLine(std::list<Position> positions)
{
    std::vector<Position> arrayPos;
    for (Position position : positions)
    {
        arrayPos.push_back(position);
    }
    Position pos = arrayPos[0];
    Direction direction = giveDirection(arrayPos[0], arrayPos[1]);
    for (unsigned i = 0; i < arrayPos.size() - 1 ; i++)
    {
        if (pos.next(direction) == arrayPos[i + 1])
        {
            pos = arrayPos[i + 1];
        }
        else
        {
            throw std::logic_error("Game.verifyDiagonalMove(), the positions are not following each other.");
        }
    }
}

void Game::verifyDiagonalMove(Move move)
{
    for (Position position : move.getPositions())
    {
        if (!board_.isFree(position.next(move.getDirection())))
        {
            throw std::logic_error("Game.verifyDiagonalMove(), the next positions isn't free !");
        }
    }
}

void Game::posCurrentColor(Position pos)
{
    if (board_.getMarble(pos)->getColor() != current_.getPlayerColor())
    {
        throw std::logic_error("Game.posCurrentColor(), the marble isn't the color of the current color.");
    }
}

void Game::removePlayerMarble(PlayerColor color)
{
    if (color == current_.getPlayerColor())
    {
        current_.removeMarble();
    }
    else
    {
        opponent_.removeMarble();
    }
}

void Game::checkMovePossible(Move move, bool changeColor,
                             bool outOrFree, bool pushOut, unsigned nbrCurrentMarble,
                             unsigned nbrOpponentMarble)
{
    if ((board_.getMarble(move.getPositions().front())->getColor() ==
            current_.getPlayerColor() && changeColor) && !pushOut)
    {
        throw std::logic_error("Game.play(), move impossible !");
    }

    if (nbrCurrentMarble < 4 && nbrOpponentMarble < nbrCurrentMarble &&
            (outOrFree || pushOut))
    {
        applyMove(move);
    }
    else
    {
        throw std::logic_error("Game.play(), move impossible !");
    }
}

void Game::applyMove(Move move)
{
    std::list<Position> positions = move.getPositions();
    Direction direction = move.getDirection();
    for (Position position : positions)
    {
        std::optional<Marble> marble = board_.getMarble(position);
        board_.removeMarble(position);
        board_.putMarble(marble, position.next(direction));
    }
}

Position Game::stringToPosition(std::string position)
{
    if (position.size() != 2)
    {
        throw std::logic_error("Game().stringToPosition(), the size is not 2 !");
    }
    char charRow = position[0];
    char charCol = position[1];
    int row = traductionRow(charRow);
    int column = (int) charCol - '0' - 1;
    return Position{row, column};

}

Direction Game::verifyDirection(Position selectPos,
                                std::string direction)
{
    Position next{stringToPosition(direction)};
    return giveDirection(selectPos, next);
}

Direction Game::giveDirection(Position startPos, Position endPos)
{
    int difRow = startPos.getRow() - endPos.getRow();
    int difCol = startPos.getColumn() - endPos.getColumn();

    if (difRow == 1 && difCol == 1)
    {
        return Direction::NO;
    }
    else if (difRow == 1 && difCol == 0)
    {
        return Direction::NE;
    }
    else if (difRow == 0 && difCol == 1)
    {
        return Direction::O;
    }
    else if (difRow == 0 && difCol == -1)
    {
        return Direction::E;
    }
    else if (difRow == -1 && difCol == 0)
    {
        return Direction::SO;
    }
    else if (difRow == -1 && difCol == -1)
    {
        return Direction::SE;
    }
    else
    {
        throw std::logic_error("Game.giveDirection(), the direction doesn't exist");
    }

}

unsigned Game::score(Player player)
{
    unsigned score{0};
    if (player == current_)
    {
        score = 14 - opponent_.getNbrMarble();
    }
    else if (player == opponent_)
    {
        score = 14 - current_.getNbrMarble();
    }
    return score;
}

Player Game::getWinner()
{
    if (current_.getNbrMarble() > opponent_.getNbrMarble())
    {
        return current_;
    }
    return opponent_;
}

void Game::swapPlayer()
{
    Player next = current_;
    current_ = opponent_;
    opponent_ = next;
}

int Game::traductionRow(char row)
{
    if (row == 'a')
    {
        return 0;
    }
    else if (row == 'b')
    {
        return 1;
    }
    else if (row == 'c')
    {
        return 2;
    }
    else if (row == 'd')
    {
        return 3;
    }
    else if (row == 'e')
    {
        return 4;
    }
    else if (row == 'f')
    {
        return 5;
    }
    else if (row == 'g')
    {
        return 6;
    }
    else if (row == 'h')
    {
        return 7;
    }
    else if (row == 'i')
    {
        return 8;
    }
    else
    {
        throw std::logic_error("Game.traductionRow(), the row isn't on the board !");
    }
}



#include "catch.hpp"
#include "../model/Game.h"

#include <list>
#include <vector>

TEST_CASE("Marble test")
{
    SECTION("Test getColor(), case BLACK")
    {
        Marble marble{PlayerColor::BLACK};
        REQUIRE(marble.getColor() == PlayerColor::BLACK);
    }

    SECTION("Test getColor(), case WHITE")
    {
        Marble marble{PlayerColor::WHITE};
        REQUIRE(marble.getColor() == PlayerColor::WHITE);
    }

    SECTION("Test operator==(), case TRUE same marble")
    {
        Marble marble{PlayerColor::WHITE};
        REQUIRE(marble == marble);
    }

    SECTION("Test operator==(), case TRUE")
    {
        Marble marble{PlayerColor::WHITE};
        Marble marble1{PlayerColor::WHITE};
        REQUIRE(marble == marble1);
    }

    SECTION("Test operator==(), case FALSE")
    {
        Marble marble{PlayerColor::WHITE};
        Marble marble1{PlayerColor::BLACK};
        REQUIRE_FALSE(marble == marble1);
    }

    SECTION("Test operator!=(), case TRUE")
    {
        Marble marble{PlayerColor::WHITE};
        Marble marble1{PlayerColor::BLACK};
        REQUIRE(marble != marble1);
    }

    SECTION("Test operator!=(), case FALSE")
    {
        Marble marble{PlayerColor::WHITE};
        Marble marble1{PlayerColor::WHITE};
        REQUIRE_FALSE(marble != marble1);
    }

    SECTION("Test operator!=(), case FALSE same marble")
    {
        Marble marble{PlayerColor::WHITE};
        REQUIRE_FALSE(marble != marble);
    }
}

//--------------------------------------------------------------------------------

TEST_CASE("Hexagon test")
{
    SECTION("Test getMarble(), case BLACK MARBLE")
    {
        Marble marble{PlayerColor::BLACK};
        Hexagon hexagon{marble};
        REQUIRE(hexagon.getMarble() == marble);
    }

    SECTION("Test getMarble(), case WHITE MARBLE")
    {
        Marble marble{PlayerColor::WHITE};
        Hexagon hexagon{marble};
        REQUIRE(hexagon.getMarble() == marble);
    }

    SECTION("Test getMarble(), case NO MARBLE")
    {
        Hexagon hexagon{};
        REQUIRE(hexagon.getMarble() == std::nullopt);
    }

    SECTION("Test putMarble(), case WHITE MARBLE")
    {
        Marble marble{PlayerColor::WHITE};
        Hexagon hexagon{};
        hexagon.putMarble(marble);
        REQUIRE(hexagon.getMarble() == marble);
    }

    SECTION("Test putMarble(), case BLACK MARBLE")
    {
        Marble marble{PlayerColor::BLACK};
        Hexagon hexagon{};
        hexagon.putMarble(marble);
        REQUIRE(hexagon.getMarble() == marble);
    }

    SECTION("Test removeMarble()")
    {
        Marble marble{PlayerColor::BLACK};
        Hexagon hexagon{marble};
        hexagon.removeMarble();
        REQUIRE(hexagon.getMarble() == std::nullopt);
    }

    SECTION("Test isFree(), case remove marble")
    {
        Marble marble{PlayerColor::BLACK};
        Hexagon hexagon{marble};
        hexagon.removeMarble();
        REQUIRE(hexagon.isFree());
    }

    SECTION("Test isFree(), case no marble")
    {
        Hexagon hexagon{};
        REQUIRE(hexagon.isFree());
    }

    SECTION("Test hasColor(), case isFree")
    {
        Hexagon hexagon{};
        REQUIRE_FALSE(hexagon.hasColor(PlayerColor::BLACK));
    }

    SECTION("Test hasColor(), case BLACK MARBLE")
    {
        Hexagon hexagon{Marble{PlayerColor::BLACK}};
        REQUIRE(hexagon.hasColor(PlayerColor::BLACK));
    }

    SECTION("Test hasColor(), case WHITE MARBLE")
    {
        Hexagon hexagon{Marble{PlayerColor::WHITE}};
        REQUIRE(hexagon.hasColor(PlayerColor::WHITE));
    }

    SECTION("Test operator==(), case TRUE same hexagon")
    {
        Hexagon hexagon{Marble{PlayerColor::WHITE}};
        REQUIRE(hexagon == hexagon);
    }

    SECTION("Test operator==(), case TRUE not same hexagon")
    {
        Hexagon hexagon{Marble{PlayerColor::WHITE}};
        Hexagon hexagon1{Marble{PlayerColor::WHITE}};
        REQUIRE(hexagon == hexagon1);
    }

    SECTION("Test operator==(), case FALSE not same hexagon")
    {
        Hexagon hexagon{Marble{PlayerColor::WHITE}};
        Hexagon hexagon1{Marble{PlayerColor::BLACK}};
        REQUIRE_FALSE(hexagon == hexagon1);
    }

    SECTION("Test operator!=(), case FALSE same hexagon")
    {
        Hexagon hexagon{Marble{PlayerColor::WHITE}};
        REQUIRE_FALSE(hexagon != hexagon);
    }

    SECTION("Test operator!=(), case FALSE not same hexagon")
    {
        Hexagon hexagon{Marble{PlayerColor::WHITE}};
        Hexagon hexagon1{Marble{PlayerColor::WHITE}};
        REQUIRE_FALSE(hexagon != hexagon1);
    }

    SECTION("Test operator!=(), case TRUE")
    {
        Hexagon hexagon{Marble{PlayerColor::WHITE}};
        Hexagon hexagon1{Marble{PlayerColor::BLACK}};
        REQUIRE(hexagon != hexagon1);
    }
}

//--------------------------------------------------------------------------------

TEST_CASE("Position test")
{
    SECTION("Test getRow(), case TRUE")
    {
        Position pos{2, 3};
        REQUIRE(pos.getRow() == 2);
    }

    SECTION("Test getRow(), case FALSE")
    {
        Position pos{2, 3};
        REQUIRE_FALSE(pos.getRow() == 3);
    }

    SECTION("Test getColumn(), case TRUE")
    {
        Position pos{2, 3};
        REQUIRE(pos.getColumn() == 3);
    }

    SECTION("Test getColumn(), case FALSE")
    {
        Position pos{2, 3};
        REQUIRE_FALSE(pos.getColumn() == 6);
    }

    SECTION("Test next(), case NO")
    {
        Position pos{4, 6};
        Position require{3, 5};
        REQUIRE(pos.next(Direction::NO) == require);
    }

    SECTION("Test next(), case NE")
    {
        Position pos{4, 6};
        Position require{3, 6};
        REQUIRE(pos.next(Direction::NE) == require);
    }

    SECTION("Test next(), case O")
    {
        Position pos{4, 6};
        Position require{4, 5};
        REQUIRE(pos.next(Direction::O) == require);
    }

    SECTION("Test next(), case E")
    {
        Position pos{4, 6};
        Position require{4, 7};
        REQUIRE(pos.next(Direction::E) == require);
    }

    SECTION("Test next(), case SO")
    {
        Position pos{4, 6};
        Position require{5, 6};
        REQUIRE(pos.next(Direction::SO) == require);
    }

    SECTION("Test next(), case SE")
    {
        Position pos{4, 6};
        Position require{5, 7};
        REQUIRE(pos.next(Direction::SE) == require);
    }

    SECTION("Test operator==(), case TRUE same position")
    {
        Position pos{4, 5};
        REQUIRE(pos == pos);
    }

    SECTION("Test operator==(), case TRUE not same position")
    {
        Position pos{4, 5};
        Position pos1{4, 5};
        REQUIRE(pos == pos1);
    }

    SECTION("Test operator==(), case FALSE not same column")
    {
        Position pos{4, 5};
        Position pos1{4, 6};
        REQUIRE_FALSE(pos == pos1);
    }

    SECTION("Test operator==(), case FALSE not same row")
    {
        Position pos{4, 5};
        Position pos1{3, 5};
        REQUIRE_FALSE(pos == pos1);
    }

    SECTION("Test operator!=(), case FALSE same position")
    {
        Position pos{4, 5};
        REQUIRE_FALSE(pos != pos);
    }

    SECTION("Test operator!=(), case FALSE not same position")
    {
        Position pos{4, 5};
        Position pos1{4, 5};
        REQUIRE_FALSE(pos != pos1);
    }

    SECTION("Test operator!=(), case TRUE")
    {
        Position pos{4, 5};
        Position pos1{4, 6};
        REQUIRE(pos != pos1);;
    }
}

//--------------------------------------------------------------------------------

TEST_CASE("Move test")
{
    SECTION("Test getPositions(), case TRUE")
    {
        Position pos1{Position{4, 4}};
        Position pos2{Position{4, 5}};
        std::list<Position> positions{pos1, pos2};
        Move move{positions, Direction::NO};
        REQUIRE(move.getPositions() == positions);
    }

    SECTION("Test getMarbles(), case FALSE")
    {
        Position pos1{Position{4, 4}};
        Position pos2{Position{4, 5}};
        std::list<Position> positions{pos1, pos2};
        std::list<Position> positions2{pos2, pos2};
        Move move{positions, Direction::NO};
        REQUIRE_FALSE(move.getPositions() == positions2);
    }

    SECTION("Test getDirection(), case TRUE")
    {
        Position pos1{Position{4, 4}};
        Position pos2{Position{4, 5}};
        std::list<Position> positions{pos1, pos2};
        Move move{positions, Direction::NO};;
        REQUIRE(move.getDirection() == Direction::NO);
    }

    SECTION("Test getDirection(), case FALSE")
    {
        Position pos1{Position{4, 4}};
        Position pos2{Position{4, 5}};
        std::list<Position> positions{pos1, pos2};
        Move move{positions, Direction::NO};
        REQUIRE_FALSE(move.getDirection() == Direction::NE);
    }
}

//--------------------------------------------------------------------------------

TEST_CASE("Player test")
{
    SECTION("Test getPlayerColor(), case TRUE")
    {
        Player player{PlayerColor::WHITE};
        REQUIRE(player.getPlayerColor() == PlayerColor::WHITE);
    }

    SECTION("Test getPlayerColor(), case FALSE")
    {
        Player player{PlayerColor::WHITE};
        REQUIRE_FALSE(player.getPlayerColor() == PlayerColor::BLACK);
    }

    SECTION("Test getNbrMarble(), case TRUE, case default nbrMarble")
    {
        Player player{PlayerColor::WHITE};
        REQUIRE(player.getNbrMarble() == 14);
    }

    SECTION("Test getNbrMarble(), case FALSE")
    {
        Player player{PlayerColor::WHITE};
        REQUIRE_FALSE(player.getNbrMarble() == 10);
    }

    SECTION("Test getNbrMarble(), case TRUE, case not default nbrMarble")
    {
        Player player{PlayerColor::WHITE, 10};
        REQUIRE(player.getNbrMarble() == 10);
    }

    SECTION("Test removeMarble(), case TRUE, case that a marble has been remove.")
    {
        Player player{PlayerColor::WHITE};
        player.removeMarble();
        REQUIRE(player.getNbrMarble() == 13);
    }

    SECTION("Test operator==(), case TRUE, case same player")
    {
        Player player{PlayerColor::WHITE, 10};
        REQUIRE(player == player);
    }

    SECTION("Test operator==(), case TRUE, case not same player")
    {
        Player player{PlayerColor::WHITE};
        Player player1{PlayerColor::WHITE, 14};
        REQUIRE(player == player1);
    }

    SECTION("Test operator==(), case FALSE, case not same COLOR")
    {
        Player player{PlayerColor::WHITE};
        Player player1{PlayerColor::BLACK, 14};
        REQUIRE_FALSE(player == player1);
    }

    SECTION("Test operator==(), case FALSE, case not same nbrMarble")
    {
        Player player{PlayerColor::WHITE};
        Player player1{PlayerColor::WHITE, 10};
        REQUIRE_FALSE(player == player1);
    }

    SECTION("Test operator!=(), case FALSE, case same player")
    {
        Player player{PlayerColor::WHITE, 10};
        REQUIRE_FALSE(player != player);
    }

    SECTION("Test operator==(), case FALSE, case not same player")
    {
        Player player{PlayerColor::WHITE};
        Player player1{PlayerColor::WHITE, 14};
        REQUIRE_FALSE(player != player1);
    }

    SECTION("Test operator==(), case TRUE, case not same COLOR")
    {
        Player player{PlayerColor::WHITE};
        Player player1{PlayerColor::BLACK, 14};
        REQUIRE(player != player1);
    }

    SECTION("Test operator==(), case TRUE, case not same nbrMarble")
    {
        Player player{PlayerColor::WHITE};
        Player player1{PlayerColor::WHITE, 10};
        REQUIRE(player != player1);
    }
}

//--------------------------------------------------------------------------------


TEST_CASE("Board test")
{
    SECTION("Test getHexagons(), case TRUE")
    {
        std::vector<std::vector<Hexagon>> hexagons =
                                           std::vector<std::vector<Hexagon>> (9, std::vector<Hexagon>(9,
                                                   Hexagon()));
        Board board;
        REQUIRE(board.getHexagons() == hexagons);
    }

    SECTION("Test getHexagons(), case FALSE")
    {
        std::vector<std::vector<Hexagon>> hexagons =
                                           std::vector<std::vector<Hexagon>> (10, std::vector<Hexagon>(10,
                                                   Hexagon()));
        Board board;
        REQUIRE_FALSE(board.getHexagons() == hexagons);
    }

    SECTION("Test isInside(), case TRUE")
    {
        Board board;
        REQUIRE(board.isInside(Position(4, 6)));
    }

    SECTION("Test isInside(), case FALSE, case the row of position is out of the board, case row = -1 ")
    {
        Board board;
        REQUIRE_FALSE(board.isInside(Position(-1, 6)));
    }

    SECTION("Test isInside(), case FALSE, case the row of position is out of the board, case row = 10 ")
    {
        Board board;
        REQUIRE_FALSE(board.isInside(Position(10, 6)));
    }

    SECTION("Test isInside(), case FALSE, case the column of position is out of the board, case column = -1 ")
    {
        Board board;
        REQUIRE_FALSE(board.isInside(Position(4, -1)));
    }

    SECTION("Test isInside(), case FALSE, case the column of position is out of the board, case column = 10 ")
    {
        Board board;
        REQUIRE_FALSE(board.isInside(Position(4, 10)));
    }

    SECTION("Test isInside(), case FALSE, case the position is a banned pos")
    {
        Board board;
        REQUIRE_FALSE(board.isInside(Position(7, 1)));
    }

    SECTION("Test getHexagon(), case TRUE")
    {
        Board board;
        REQUIRE(board.getHexagon(Position{4, 6}) == Hexagon{});
    }

    SECTION("Test getHexagon(), case FALSE, case position out of the board !")
    {
        Board board;
        REQUIRE_THROWS(board.getHexagon(Position{10, 10}));
    }

    SECTION("Test putMarble()")
    {
        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 6});
        REQUIRE(board.getHexagon(Position{4, 6}) == Hexagon{Marble{PlayerColor::WHITE}});
    }

    SECTION("Test putMarble(), case position out of board")
    {
        Board board;
        REQUIRE_THROWS(board.putMarble(Marble{PlayerColor::WHITE}, Position{1, 7}));
    }

    SECTION("Test putMarble(), case position isn't free")
    {
        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 6});
        REQUIRE_THROWS(board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 6}));
    }

    SECTION("Test isFree(), case TRUE")
    {
        Board board;
        REQUIRE(board.isFree(Position{4, 6}));
    }

    SECTION("Test isFree(), case FALSE, position already occupied")
    {
        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 6});
        REQUIRE_FALSE(board.isFree(Position{4, 6}));
    }

    SECTION("Test isFree(), case FALSE, position isn't inside the board")
    {
        Board board;
        REQUIRE_THROWS(board.isFree(Position{10, 10}));
    }

    SECTION("Test hasColor(), case TRUE, case white marble.")
    {
        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 6});
        REQUIRE(board.hasColor(Position{4, 6}, PlayerColor::WHITE));
    }

    SECTION("Test hasColor(), case TRUE, case black marble.")
    {
        Board board;
        board.putMarble(Marble{PlayerColor::BLACK}, Position{4, 6});
        REQUIRE(board.hasColor(Position{4, 6}, PlayerColor::BLACK));
    }

    SECTION("Test hasColor(), case false, case not same color marble.")
    {
        Board board;
        board.putMarble(Marble{PlayerColor::BLACK}, Position{4, 6});
        REQUIRE_FALSE(board.hasColor(Position{4, 6}, PlayerColor::WHITE));
    }

    SECTION("Test getMarble(), case no marble")
    {
        Board board;
        REQUIRE(board.getMarble(Position{4, 6}) == std::nullopt);
    }

    SECTION("Test getMarble(), case WHITE marble")
    {
        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 6});
        REQUIRE(board.getMarble(Position{4, 6}) == Marble{PlayerColor::WHITE});
    }

    SECTION("Test getMarble(), case BLACK marble")
    {
        Board board;
        board.putMarble(Marble{PlayerColor::BLACK}, Position{4, 6});
        REQUIRE(board.getMarble(Position{4, 6}) == Marble{PlayerColor::BLACK});
    }

    SECTION("Test removeMarble()")
    {
        Board board;
        board.putMarble(Marble{PlayerColor::BLACK}, Position{4, 6});
        board.removeMarble(Position{4, 6});
        REQUIRE(board.isFree(Position{4, 6}));
    }

    SECTION("Test removeMarble(), case position isn't inside !")
    {
        Board board;
        REQUIRE_THROWS(board.removeMarble(Position{1, 7}));
    }

    SECTION("Test removeMarble(), case position is Free !")
    {
        Board board;
        REQUIRE_THROWS(board.removeMarble(Position{4, 6}));
    }

    SECTION("Test operator==(), case TRUE, case same board")
    {
        Board board;
        REQUIRE(board == board);
    }

    SECTION("Test operator==(), case TRUE, case not same board")
    {
        Board board;
        Board board1;
        REQUIRE(board == board1);
    }

    SECTION("Test operator==(), case FALSE, case add marble on the board")
    {
        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 6});
        Board board1;
        REQUIRE_FALSE(board == board1);
    }

    SECTION("Test operator==(), case TRUE, case add and remove marble on the board")
    {
        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 6});
        board.removeMarble(Position{4, 6});
        Board board1;
        REQUIRE(board == board1);
    }

    SECTION("Test operator!=(), case FALSE, case same board")
    {
        Board board;
        REQUIRE_FALSE(board != board);
    }

    SECTION("Test operator!=(), case FALSE, case not same board")
    {
        Board board;
        Board board1;
        REQUIRE_FALSE(board != board1);
    }

    SECTION("Test operator!=(), case TRUE, case add marble on the board")
    {
        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 6});
        Board board1;
        REQUIRE(board != board1);
    }

    SECTION("Test operator!=(), case FALSE, case add and remove marble on the board")
    {
        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 6});
        board.removeMarble(Position{4, 6});
        Board board1;
        REQUIRE_FALSE(board != board1);
    }
}

//--------------------------------------------------------------------------------

TEST_CASE("Game test")
{
    SECTION("Test getBoard(), case TRUE")
    {
        Game game;
        Board board;
        REQUIRE(game.getBoard() == board);
    }

    SECTION("Test getBoard(), case FALSE")
    {
        Game game;
        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 6});
        REQUIRE_FALSE(game.getBoard() == board);
    }

    SECTION("Test getCurrent(), case TRUE")
    {
        Game game;
        REQUIRE(game.getCurrent() == Player{PlayerColor::WHITE});
    }

    SECTION("Test getCurrent(), case FALSE")
    {
        Game game;
        REQUIRE_FALSE(game.getCurrent() == Player{PlayerColor::BLACK});
    }

    SECTION("Test getOpponent(), case TRUE")
    {
        Game game;
        REQUIRE(game.getOpponent() == Player{PlayerColor::BLACK});
    }

    SECTION("Test getOpponent(), case FALSE")
    {
        Game game;
        REQUIRE_FALSE(game.getOpponent() == Player{PlayerColor::WHITE});
    }

    SECTION("Test initialise()")
    {
        Game game;
        game.initialise();
        Board board;
        REQUIRE(game.getBoard() != board);
    }

    SECTION("Test isOver(),case TRUE, case current lose")
    {
        Game game;
        for (unsigned i = 0 ; i < 7 ; i++)
        {
            game.getCurrent().removeMarble();
        }
        REQUIRE(game.isOver());
    }

    SECTION("Test isOver(),case TRUE, case opponent lose")
    {
        Game game;
        for (unsigned i = 0 ; i < 7 ; i++)
        {
            game.getOpponent().removeMarble();
        }
        REQUIRE(game.isOver());
    }

    SECTION("Test isOver(),case FALSE")
    {
        Game game;
        REQUIRE_FALSE(game.isOver());
    }

    SECTION("Test play(),case wrong command: play a2")
    {
        std::vector<std::string> command{"play", "a2"};
        Game game;
        game.initialise();
        REQUIRE_THROWS(game.play(command));
    }

    SECTION("Test play(),case wrong command: play aa")
    {
        std::vector<std::string> command{"play", "aa"};
        Game game;
        game.initialise();
        REQUIRE_THROWS(game.play(command));
    }

    SECTION("Test play(),case wrong command: play")
    {
        std::vector<std::string> command{"play"};
        Game game;
        game.initialise();
        REQUIRE_THROWS(game.play(command));
    }

    SECTION("Test play(),case wrong command: play a")
    {
        std::vector<std::string> command{"play", "a"};
        Game game;
        game.initialise();
        REQUIRE_THROWS(game.play(command));
    }

    SECTION("Test play(),case wrong command: play aaa")
    {
        std::vector<std::string> command{"play", "aaa"};
        Game game;
        game.initialise();
        REQUIRE_THROWS(game.play(command));
    }

    SECTION("Test play(),case wrong command: play e4e3")
    {
        std::vector<std::string> command{"play", "e4e3"};
        Game game;
        game.initialise();
        REQUIRE_THROWS(game.play(command));
    }

    SECTION("Test play(),case wrong command: play e4e3e3e6")
    {
        std::vector<std::string> command{"play", "e4e3e3e6"};
        Game game;
        game.initialise();
        REQUIRE_THROWS(game.play(command));
    }

    SECTION("Test play(),case wrong command: play e4e3 e3e6")
    {
        std::vector<std::string> command{"play", "e4e3", "e3e6"};
        Game game;
        game.initialise();
        REQUIRE_THROWS(game.play(command));
    }

    SECTION("Test play(),case wrong line command: 1v1")
    {
        std::vector<std::string> command{"play", "e5e4"};
        Game game;
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        game.getBoard().putMarble(Marble{PlayerColor::BLACK}, Position{4, 3});
        REQUIRE_THROWS(game.play(command));
    }

    SECTION("Test play(),case wrong line command: 2v2")
    {
        std::vector<std::string> command{"play", "e5e4"};
        Game game;
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 3});
        game.getBoard().putMarble(Marble{PlayerColor::BLACK}, Position{4, 2});
        game.getBoard().putMarble(Marble{PlayerColor::BLACK}, Position{4, 1});
        REQUIRE_THROWS(game.play(command));
    }

    SECTION("Test play(),case wrong line command: 3v3")
    {
        std::vector<std::string> command{"play", "e6e5"};
        Game game;
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 5});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 3});
        game.getBoard().putMarble(Marble{PlayerColor::BLACK}, Position{4, 2});
        game.getBoard().putMarble(Marble{PlayerColor::BLACK}, Position{4, 1});
        game.getBoard().putMarble(Marble{PlayerColor::BLACK}, Position{4, 0});
        REQUIRE_THROWS(game.play(command));
    }

    SECTION("Test play(),case good line command: 2v1")
    {
        std::vector<std::string> command{"play", "e5e4"};
        Game game;
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 3});
        game.getBoard().putMarble(Marble{PlayerColor::BLACK}, Position{4, 2});
        game.play(command);

        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 3});
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 2});
        board.putMarble(Marble{PlayerColor::BLACK}, Position{4, 1});
        REQUIRE(game.getBoard() == board);
    }

    SECTION("Test play(),case good line command: 3v1")
    {
        std::vector<std::string> command{"play", "e6e5"};
        Game game;
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 5});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 3});
        game.getBoard().putMarble(Marble{PlayerColor::BLACK}, Position{4, 2});
        game.play(command);

        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 3});
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 2});
        board.putMarble(Marble{PlayerColor::BLACK}, Position{4, 1});
        REQUIRE(game.getBoard() == board);
    }

    SECTION("Test play(),case good line command: 3v2")
    {
        std::vector<std::string> command{"play", "e6e5"};
        Game game;
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 5});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 3});
        game.getBoard().putMarble(Marble{PlayerColor::BLACK}, Position{4, 2});
        game.getBoard().putMarble(Marble{PlayerColor::BLACK}, Position{4, 1});
        game.play(command);

        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 3});
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 2});
        board.putMarble(Marble{PlayerColor::BLACK}, Position{4, 1});
        board.putMarble(Marble{PlayerColor::BLACK}, Position{4, 0});
        REQUIRE(game.getBoard() == board);
    }

    SECTION("Test play(),case wrong line command: marble behind same color")
    {
        std::vector<std::string> command{"play", "e6e5"};
        Game game;
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 5});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 3});
        game.getBoard().putMarble(Marble{PlayerColor::BLACK}, Position{4, 2});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 1});
        REQUIRE_THROWS(game.play(command));
    }

    SECTION("Test play(),case good line command: push just one marble current color")
    {
        std::vector<std::string> command{"play", "e6e5"};
        Game game;
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 5});
        game.play(command);

        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        REQUIRE(game.getBoard() == board);
    }

    SECTION("Test play(),case good line command: push 2 marble current color")
    {
        std::vector<std::string> command{"play", "e6e5"};
        Game game;
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 5});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        game.play(command);

        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 3});
        REQUIRE(game.getBoard() == board);
    }

    SECTION("Test play(),case good line command: push 3 marble current color")
    {
        std::vector<std::string> command{"play", "e6e5"};
        Game game;
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 5});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 3});
        game.play(command);

        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 3});
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 2});
        REQUIRE(game.getBoard() == board);
    }

    SECTION("Test play(),case good line command: push an opponent marble out of the board")
    {
        std::vector<std::string> command{"play", "e3e2"};
        Game game;
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 2});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 1});
        game.getBoard().putMarble(Marble{PlayerColor::BLACK}, Position{4, 0});
        game.play(command);

        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 1});
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 0});
        REQUIRE(game.getBoard() == board);
    }

    SECTION("Test play(),case good diagonal command: move 3 marbles in NW")
    {
        std::vector<std::string> command{"play", "e3e5d2"};
        Game game;
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 3});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 2});
        game.play(command);

        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{3, 1});
        board.putMarble(Marble{PlayerColor::WHITE}, Position{3, 2});
        board.putMarble(Marble{PlayerColor::WHITE}, Position{3, 3});
        REQUIRE(game.getBoard() == board);
    }

    SECTION("Test play(),case good diagonal command: move 3 marbles in NE")
    {
        std::vector<std::string> command{"play", "e3e5d3"};
        Game game;
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 3});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 2});
        game.play(command);

        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{3, 2});
        board.putMarble(Marble{PlayerColor::WHITE}, Position{3, 3});
        board.putMarble(Marble{PlayerColor::WHITE}, Position{3, 4});
        REQUIRE(game.getBoard() == board);
    }

    SECTION("Test play(),case good diagonal command: move 3 marbles in SW")
    {
        std::vector<std::string> command{"play", "e3e5f3"};
        Game game;
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 3});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 2});
        game.play(command);

        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{5, 2});
        board.putMarble(Marble{PlayerColor::WHITE}, Position{5, 3});
        board.putMarble(Marble{PlayerColor::WHITE}, Position{5, 4});
        REQUIRE(game.getBoard() == board);
    }

    SECTION("Test play(),case good diagonal command: move 3 marbles in SE")
    {
        std::vector<std::string> command{"play", "e3e5f4"};
        Game game;
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 3});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 2});
        game.play(command);

        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{5, 3});
        board.putMarble(Marble{PlayerColor::WHITE}, Position{5, 4});
        board.putMarble(Marble{PlayerColor::WHITE}, Position{5, 5});
        REQUIRE(game.getBoard() == board);
    }

    SECTION("Test play(),case good diagonal command: move 3 marbles in W")
    {
        std::vector<std::string> command{"play", "d5f5d4"};
        Game game;
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{3, 4});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{5, 4});
        game.play(command);

        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{3, 3});
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 3});
        board.putMarble(Marble{PlayerColor::WHITE}, Position{5, 3});
        REQUIRE(game.getBoard() == board);
    }

    SECTION("Test play(),case good diagonal command: move 3 marbles in E")
    {
        std::vector<std::string> command{"play", "d5f5d6"};
        Game game;
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{3, 4});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{5, 4});
        game.play(command);

        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{3, 5});
        board.putMarble(Marble{PlayerColor::WHITE}, Position{4, 5});
        board.putMarble(Marble{PlayerColor::WHITE}, Position{5, 5});
        REQUIRE(game.getBoard() == board);
    }

    SECTION("Test play(),case good diagonal command: move 2 marbles in NW")
    {
        std::vector<std::string> command{"play", "e4e5d3"};
        Game game;
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 3});
        game.play(command);

        Board board;
        board.putMarble(Marble{PlayerColor::WHITE}, Position{3, 2});
        board.putMarble(Marble{PlayerColor::WHITE}, Position{3, 3});
        REQUIRE(game.getBoard() == board);
    }

    SECTION("Test play(),case wrong diagonal command: marbles are not following each other")
    {
        std::vector<std::string> command{"play", "e3e7d2"};
        Game game;
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 6});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 2});
        REQUIRE_THROWS(game.play(command));
    }

    SECTION("Test play(),case wrong diagonal command: wrong direction")
    {
        std::vector<std::string> command{"play", "e3e5a3"};
        Game game;
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 3});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 2});
        REQUIRE_THROWS(game.play(command));
    }

    SECTION("Test play(),case wrong diagonal command: not all final pos are free")
    {
        std::vector<std::string> command{"play", "e3e5d3"};
        Game game;
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 4});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 3});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{4, 2});
        game.getBoard().putMarble(Marble{PlayerColor::WHITE}, Position{3, 3});
        REQUIRE_THROWS(game.play(command));
    }

    SECTION("Test score(),case current")
    {
        Game game;
        REQUIRE(game.score(Player{PlayerColor::WHITE}) == 0);
    }

    SECTION("Test score(),case opponent")
    {
        Game game;
        REQUIRE(game.score(Player{PlayerColor::BLACK}) == 0);
    }

    SECTION("Test score(),case current, remove marble opponent")
    {
        Game game;
        game.getOpponent().removeMarble();
        REQUIRE(game.score(Player{PlayerColor::WHITE}) == 1);
    }

    SECTION("Test getWinner(),case current")
    {
        Game game;
        game.getOpponent().removeMarble();
        REQUIRE(game.getWinner() == game.getCurrent());
    }

    SECTION("Test getWinner(),case opponent")
    {
        Game game;
        game.getCurrent().removeMarble();
        REQUIRE(game.getWinner() == game.getOpponent());
    }
}

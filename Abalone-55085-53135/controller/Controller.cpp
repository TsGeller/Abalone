#include "Controller.h"

using namespace std;

Controller::Controller(Game * game, View view): game_(game),
    view_(view) {}

void Controller::initialise()
{
    game_->initialise();
    view_.initialise();
}

void Controller::startGame()
{
    view_.displayHelp();
    bool gameIsOver = game_->isOver();
    loopGame(gameIsOver);
    view_.displayWinner(game_->getWinner());
    view_.quit();
}

void Controller::loopGame(bool gameIsOver)
{
    bool gameIsOverByQuit{false};
    while (!gameIsOver && !gameIsOverByQuit)
    {
        view_.update(game_);
        string command{view_.askCommand()};
        vector<string> arrayCommand = tabCommand(command);
        gameIsOverByQuit = checkAnswer(arrayCommand);
        gameIsOver = game_->isOver();
    }
}

bool Controller::checkAnswer(vector<string> arrayCommand)
{

    if (arrayCommand[0] == "quit")
    {
        return true;
    }
    else if (arrayCommand[0] == "show")
    {
        view_.displayBoard(game_->getBoard());
    }
    else if (arrayCommand[0] == "score")
    {
        view_.theScore();
    }
    else if (arrayCommand[0] == "help")
    {
        view_.displayHelp();
    }
    else if (arrayCommand[0] == "play")
    {
        checkAnswerPlay(arrayCommand);
    }
    else
    {
        view_.printWrongCommand();
    }


    return false;
}

void Controller::checkAnswerPlay(vector<string> arrayCommand)
{
    if (arrayCommand.size() == 2)
    {
        try
        {
            game_->play(arrayCommand);
        }
        catch (logic_error)
        {
            view_.printWrongCommand();
        }
    }
    else
    {
        view_.printWrongCommand();
    }
}

//https://www.geeksforgeeks.org/how-to-split-a-string-in-cc-python-and-java/
vector<string> Controller::tabCommand(string command)
{
    vector<string> arrayCommand;
    string del = " ";
    int start = 0;
    int end = command.find(del);
    while (end != -1)
    {
        arrayCommand.push_back(command.substr(start, end - start));
        start = end + del.size();
        end = command.find(del, start);
    }
    arrayCommand.push_back(command.substr(start, end - start));
    return arrayCommand;
}

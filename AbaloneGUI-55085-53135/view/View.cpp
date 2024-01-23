#include "View.h"

#include <algorithm>

using namespace std;

View::View(Game * subject): subject_(subject)
{
    subject_->registerObserver(this);
}

void View::update(const nvs::Subject * subject)
{
    if (subject != subject_) return;
    separationView(80);
    printCurrentPlayer(subject_->getCurrent());
    displayBoard(subject_->getBoard());
}

void View::initialise()
{
    cout << "Bienvenue au jeu Abalone !" << endl;
    cout << endl;
}

void View::quit()
{
    cout << "Au revoir !" << endl;
    cout << endl;
}

void View::displayHelp()
{
    cout << "Commandes: " << endl;
    cout << "- help : montre toutes les commandes" << endl;
    cout << "- score : montre le nombre de piece que les joueurs ont prit a leur adversaire"
         << endl;
    cout << "- play [ABA-PRO] : deplace une piece"
         << endl;
    cout << "- show : montre le plateau" << endl;
    cout << "- quit : quitte le jeu" << endl;
    cout << endl;
}

string View::askCommand()
{
    string command;
    cout << "Entrez votre commande: ";
    getline(cin, command);
    cout << endl;
    for_each(command.begin(), command.end(), [](char & c)
    {
        c = ::tolower(c);
    });
    return command;
}

void View::theScore()
{
    cout << "Le score des " << colorName(
             subject_->getCurrent().getPlayerColor()) <<  " est de " <<
         subject_->score(subject_->getCurrent()) << " !" << endl;

    cout << "Le score des " << colorName(
             subject_->getOpponent().getPlayerColor()) <<  " est de " <<
         subject_->score(subject_->getOpponent()) << " !" << endl;
    cout << endl;
}

void View::displayWinner(Player player)
{
    separationView(80);
    displayBoard(subject_->getBoard());
    cout << "Le gagnant est " << colorName(player.getPlayerColor()) <<
         " !" << endl;
    cout << endl;
    theScore();
}

void View::displayBoard(Board & board)
{
    cout << "        1 2 3 4 5 " << endl;
    cout << "    A  ";
    for (int i = 0; i <= 4; i++)
    {
        printTypeMarble(board, Position{0, i});
    }
    cout << " 6" << endl;
    cout << "   B  ";
    for (int i = 0; i <= 5; i++)
    {
        printTypeMarble(board, Position{1, i});
    }
    cout << " 7" << endl;
    cout << "  C  ";
    for (int i = 0; i <= 6; i++)
    {
        printTypeMarble(board, Position{2, i});
    }
    cout << " 8" << endl;
    cout << " D  ";
    for (int i = 0; i <= 7; i++)
    {
        printTypeMarble(board, Position{3, i});
    }
    cout << " 9" << endl;
    cout << "E  ";
    for (int i = 0; i <= 8; i++)
    {
        printTypeMarble(board, Position{4, i});
    }
    cout << "" << endl;
    cout << " F  ";
    for (int i = 1; i <= 8; i++)
    {
        printTypeMarble(board, Position{5, i});
    }
    cout << "" << endl;
    cout << "  G  ";
    for (int i = 2; i <= 8; i++)
    {
        printTypeMarble(board, Position{6, i});
    }
    cout << "" << endl;
    cout << "   H  ";
    for (int i = 3; i <= 8; i++)
    {
        printTypeMarble(board, Position{7, i});
    }
    cout << "" << endl;
    cout << "    I  ";
    for (int i = 4; i <= 8; i++)
    {
        printTypeMarble(board, Position{8, i});
    }
    cout << endl;
    cout << endl;
}

void View::printImpossibleMovement()
{
    cout << "Mouvement impossible !" << endl;
}

void View::printCurrentPlayer(Player player)
{
    cout << "C'est au tour des " << colorName(player.getPlayerColor()) <<
         " !" << endl;
    cout << endl;
}

void View::printWrongCommand()
{
    cout << "Vous avez entre une mauvaise commande, entrez en une nouvelle"
         " svp !" << endl;
    cout << endl;
}

void View::separationView(unsigned length)
{
    for (unsigned i = 0; i < length ; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << endl;
}

void View::printTypeMarble(Board & board, Position pos)
{
    if (board.hasColor(pos, PlayerColor::BLACK))
    {
        cout << "N ";
    }
    else if (board.hasColor(pos, PlayerColor::WHITE))
    {
        cout << "B ";
    }
    else
    {
        cout << ". ";
    }
}

string View::colorName(PlayerColor color)
{
    if (color == PlayerColor::WHITE)
    {
        return "blanc";
    }
    return "noir";
}





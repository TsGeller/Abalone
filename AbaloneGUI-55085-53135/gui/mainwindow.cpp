#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <cmath>

MainWindow::MainWindow(QWidget * parent, Game * subject) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _subject(subject),
    _hexaCells{}
{
    _subject->registerObserver(this);

    ui->setupUi(this);

    setUpBoard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update(const nvs::Subject * subject)
{
    if (subject != _subject) return;
    updateBoard();
    updateTurnPlayer();
    updateScore();
}

void MainWindow::updateBoard()
{
    for (HexaCell * e : _hexaCells)
    {
        Position pos{stringToPosition(e->getPos())};
        if (_subject->getBoard().hasColor(pos, PlayerColor::WHITE))
        {
            e->setColor(1);
            e->update();
        }
        else if (_subject->getBoard().hasColor(pos, PlayerColor::BLACK))
        {
            e->setColor(2);
            e->update();
        }
        else
        {
            e->setColor(0);
            e->update();
        }
    }
}

void MainWindow::updateTurnPlayer()
{
    PlayerColor color{_subject->getCurrent().getPlayerColor()};
    std::string colorStr;
    if (color == PlayerColor::WHITE)
    {
        colorStr = "Blanc";
    }
    else
    {
        colorStr = "Noir";
    }
    ui->currentPlayerLabel->setText(colorStr.c_str());
}

void MainWindow::updateScore()
{
    PlayerColor colorCurrent{_subject->getCurrent().getPlayerColor()};
    unsigned scoreWhite, scoreBlack;
    if (colorCurrent == PlayerColor::WHITE)
    {
        scoreWhite = _subject->score(_subject->getCurrent());
        scoreBlack = _subject->score(_subject->getOpponent());
    }
    else
    {
        scoreWhite = _subject->score(_subject->getOpponent());
        scoreBlack = _subject->score(_subject->getCurrent());
    }
    ui->scoreWhiteLabel->setText(QString::number(scoreWhite));
    ui->scoreBlackLabel->setText(QString::number(scoreBlack));
}



void MainWindow::on_playButton_clicked()
{
    std::string abaPro = ui->commandLabel->text().toStdString();
    qDebug() << abaPro.c_str();
    try
    {
        _subject->play(abaPro);
        update(_subject);
        on_deleteButton_clicked();
        ui->infoLabel->setText("Mouvement appliqué !");
    }
    catch (std::logic_error)
    {
        ui->infoLabel->setText("Erreur, choississez d'autres cases.");
        on_deleteButton_clicked();
    }
}

void MainWindow::on_hexacell_clicked(std::string value)
{
    unsigned size = ui->commandLabel->text().size();
    if (size < 6)
    {
        ui->commandLabel->setText(ui->commandLabel->text().append(
                                      value.c_str()));
    }
}

void MainWindow::on_deleteButton_clicked()
{
    for (HexaCell * e : _hexaCells)
    {
        e->unselect();
    }
    ui->commandLabel->setText("");
}

void MainWindow::on_restartButton_clicked()
{
    _subject->initialise();
    update(_subject);
    ui->infoLabel->setText("Le jeu à redémarrer!");
}

void MainWindow::setUpBoard()
{
    QGraphicsScene * scene = new QGraphicsScene();

    createHexaCells();

    for (HexaCell * e : _hexaCells)
    {
        scene->addItem(e);
        QObject::connect(e,
                         &HexaCell::sendValue,
                         this,
                         &MainWindow::on_hexacell_clicked);
    }

    QGraphicsView * view = new QGraphicsView(scene);

    view->setRenderHint(QPainter::Antialiasing);
    view->setRenderHint(QPainter::TextAntialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(
        QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::ScrollHandDrag);

    view->update();

    ui->boardLayout->addWidget(view);
}

void MainWindow::createHexaCells()
{
    double rad = 25;
    double width = sqrt(3) * rad;
    double height = 2 * rad;

    //LIGNE +4
    _hexaCells.push_back(new HexaCell(rad,
                                      -2 * width,
                                      -((height / 4) * 3) * 4,
                                      1,
                                      "a1",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      -width,
                                      -((height / 4) * 3) * 4,
                                      2,
                                      "a2",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      0,
                                      -((height / 4) * 3) * 4,
                                      1,
                                      "a3",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      width,
                                      -((height / 4) * 3) * 4,
                                      1,
                                      "a4",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      2 * width,
                                      -((height / 4) * 3) * 4,
                                      0,
                                      "a5",
                                      nullptr));

    //LIGNE +3
    _hexaCells.push_back(new HexaCell(rad,
                                      -(width / 2) * 5,
                                      -((height / 4) * 3) * 3,
                                      0,
                                      "b1",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      -(width / 2) * 3,
                                      -((height / 4) * 3) * 3,
                                      0,
                                      "b2",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      -width / 2,
                                      -((height / 4) * 3) * 3,
                                      0,
                                      "b3",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      width / 2,
                                      -((height / 4) * 3) * 3,
                                      0,
                                      "b4",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      (width / 2) * 3,
                                      -((height / 4) * 3) * 3,
                                      0,
                                      "b5",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      (width / 2) * 5,
                                      -((height / 4) * 3) * 3,
                                      0,
                                      "b6",
                                      nullptr));

    //LIGNE +2
    _hexaCells.push_back(new HexaCell(rad,
                                      -3 * width,
                                      -((height / 4) * 3) * 2,
                                      0,
                                      "c1",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      -2 * width,
                                      -((height / 4) * 3) * 2,
                                      0,
                                      "c2",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      -width,
                                      -((height / 4) * 3) * 2,
                                      0,
                                      "c3",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      0,
                                      -((height / 4) * 3) * 2,
                                      0,
                                      "c4",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      width,
                                      -((height / 4) * 3) * 2,
                                      0,
                                      "c5",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      2 * width,
                                      -((height / 4) * 3) * 2,
                                      0,
                                      "c6",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      3 * width,
                                      -((height / 4) * 3) * 2,
                                      0,
                                      "c7",
                                      nullptr));

    //LIGNE +1
    _hexaCells.push_back(new HexaCell(rad,
                                      (-width * 7) / 2,
                                      -(height / 4) * 3,
                                      0,
                                      "d1",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      (-width * 5) / 2,
                                      -(height / 4) * 3,
                                      0,
                                      "d2",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      (-width * 3) / 2,
                                      -(height / 4) * 3,
                                      0,
                                      "d3",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      -width / 2,
                                      -(height / 4) * 3,
                                      0,
                                      "d4",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      width / 2,
                                      -(height / 4) * 3,
                                      0,
                                      "d5",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      (width * 3) / 2,
                                      -(height / 4) * 3,
                                      0,
                                      "d6",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      (width * 5) / 2,
                                      -(height / 4) * 3,
                                      0,
                                      "d7",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      (width * 7) / 2,
                                      -(height / 4) * 3,
                                      0,
                                      "d8",
                                      nullptr));

    // LIGNE 0
    _hexaCells.push_back(new HexaCell(rad, -4 * width, 0, 0, "e1",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad, -3 * width, 0, 0, "e2",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad, -2 * width, 0, 0, "e3",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad, -1 * width, 0, 0, "e4",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad, 0, 0, 0, "e5", nullptr));
    _hexaCells.push_back(new HexaCell(rad, 1 * width, 0, 0, "e6",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad, 2 * width, 0, 0, "e7",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad, 3 * width, 0, 0, "e8",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad, 4 * width, 0, 0, "e9",
                                      nullptr));

    //LIGNE -1
    _hexaCells.push_back(new HexaCell(rad,
                                      -(width / 2) * 7,
                                      ((height / 4) * 3) * 1,
                                      0,
                                      "f2",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      -(width / 2) * 5,
                                      ((height / 4) * 3) * 1,
                                      0,
                                      "f3",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      -(width / 2) * 3,
                                      ((height / 4) * 3) * 1,
                                      0,
                                      "f4",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      -width / 2,
                                      ((height / 4) * 3) * 1,
                                      0,
                                      "f5",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      width / 2,
                                      ((height / 4) * 3) * 1,
                                      0,
                                      "f6",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      (width / 2) * 3,
                                      ((height / 4) * 3) * 1,
                                      0,
                                      "f7",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      (width / 2) * 5,
                                      ((height / 4) * 3) * 1,
                                      0,
                                      "f8",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      (width / 2) * 7,
                                      ((height / 4) * 3) * 1,
                                      0,
                                      "f9",
                                      nullptr));

    //LIGNE -2
    _hexaCells.push_back(new HexaCell(rad,
                                      -3 * width,
                                      ((height / 4) * 3) * 2,
                                      0,
                                      "g3",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      -2 * width,
                                      ((height / 4) * 3) * 2,
                                      0,
                                      "g4",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      -width,
                                      ((height / 4) * 3) * 2,
                                      0,
                                      "g5",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      0,
                                      ((height / 4) * 3) * 2,
                                      0,
                                      "g6",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      width,
                                      ((height / 4) * 3) * 2,
                                      0,
                                      "g7",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      2 * width,
                                      ((height / 4) * 3) * 2,
                                      0,
                                      "g8",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      3 * width,
                                      ((height / 4) * 3) * 2,
                                      0,
                                      "g9",
                                      nullptr));

    //LIGNE -3
    _hexaCells.push_back(new HexaCell(rad,
                                      -(width / 2) * 5,
                                      ((height / 4) * 3) * 3,
                                      0,
                                      "h4",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      -(width / 2) * 3,
                                      ((height / 4) * 3) * 3,
                                      0,
                                      "h5",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      -width / 2,
                                      ((height / 4) * 3) * 3,
                                      0,
                                      "h6",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      width / 2,
                                      ((height / 4) * 3) * 3,
                                      0,
                                      "h7",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      (width / 2) * 3,
                                      ((height / 4) * 3) * 3,
                                      0,
                                      "h8",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      (width / 2) * 5,
                                      ((height / 4) * 3) * 3,
                                      0,
                                      "h9",
                                      nullptr));

    //LIGNE -4
    _hexaCells.push_back(new HexaCell(rad,
                                      -2 * width,
                                      ((height / 4) * 3) * 4,
                                      0,
                                      "i5",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      -width,
                                      ((height / 4) * 3) * 4,
                                      0,
                                      "i6",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      0,
                                      ((height / 4) * 3) * 4,
                                      0,
                                      "i7",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      width,
                                      ((height / 4) * 3) * 4,
                                      0,
                                      "i8",
                                      nullptr));
    _hexaCells.push_back(new HexaCell(rad,
                                      2 * width,
                                      ((height / 4) * 3) * 4,
                                      0,
                                      "i9",
                                      nullptr));
}

Position MainWindow::stringToPosition(std::string strPos)
{
    char charRow = strPos[0];
    char charCol = strPos[1];
    int row = traductionRow(charRow);
    int column = (int) charCol - '0' - 1;
    return Position{row, column};
}

int MainWindow::traductionRow(char row)
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
        throw std::logic_error("");
    }
}

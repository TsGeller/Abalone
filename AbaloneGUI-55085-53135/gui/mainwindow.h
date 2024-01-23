#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "hexacell.h"
#include "../model/dp/Observer.h"
#include "../model/dp/Subject.h"
#include "../model/Game.h"

#include <QMainWindow>
// espace de nom UI
namespace Ui
{
/**
 *Class mainWindow to display ui of abalone
 */

class MainWindow;
}

class MainWindow : public QMainWindow, public nvs::Observer
{
    Q_OBJECT

  public:
    /**
     * @brief MainWindow constructor of mainWindow
     * @param parent widget parent
     * @param subject subject obsevable
     */
    explicit MainWindow(QWidget * parent = nullptr,
                        Game * subject = nullptr);
    ~MainWindow();
    /**
     * @brief update update the board when there is a movement
     */
    virtual void update(const nvs::Subject *) override;

  private slots:
    /**
     * @brief on_hexacell_clickedevent when hexacell is clicked
     * @param value
     */
    void on_hexacell_clicked(std::string value);
    /**
     * @brief on_playButton_clicked event when play button is clicked
     */
    void on_playButton_clicked();
    /**
     * @brief on_deleteButton_clicked event when delete button is cliked
     */
    void on_deleteButton_clicked();
    /**
     * @brief on_restartButton_clicked event when restart button is clicked
     */
    void on_restartButton_clicked();

  private:
    Ui::MainWindow * ui;// attributes Maiinwindows
    Game * _subject;// subject games
    std::vector<HexaCell *> _hexaCells; //attribues list of hexacells

  private:
    /**
     * @brief setUpBoard set up the board
     */
    void setUpBoard();
    /**
     * @brief createHexaCells create hexacell
     */
    void createHexaCells();
    /**
     * @brief updateBoard update the board
     */
    void updateBoard();
    /**
     * @brief updateTurnPlayer update turnPlayer
     */
    void updateTurnPlayer();
    /**
     * @brief updateScore update the score of the player
     */
    void updateScore();
    /**
     * @brief stringToPosition convert string position to position
     * @return
     */
    Position stringToPosition(std::string);
    /**
     * @brief traductionRow convert the traduction string in int
     * @return int row
     */
    int traductionRow(char);

};

#endif // MAINWINDOW_H

#include "gui/mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

MainWindow::MainWindow(QWidget * parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    gHexaCells_{}
{
    ui->setupUi(this);

    gHexaCells_.push_back(new GHexaCell(0, 0, 50, "00", nullptr));
    gHexaCells_.push_back(new GHexaCell(0, sqrt(3) * 50, 50, "01",
                                        nullptr));
    gHexaCells_.push_back(new GHexaCell(2 * 50 * 3 / 4, sqrt(3) * 50 / 2,
                                        50, "10",
                                        nullptr));

    auto scene = new QGraphicsScene();

    std::for_each(begin(gHexaCells_), end(gHexaCells_),
                  [this, scene](GHexaCell * e)
    {
        e->setPos(e->y(), e->x());
        scene->addItem(e);
        QObject::connect(e,
                         SIGNAL(sendValue(std::string)),
                         this,
                         SLOT(on_ghexacell_clicked(std::string)));
    });

    auto view = new QGraphicsView(scene);
    view->update();
    ui->verticalLayout->addWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ghe

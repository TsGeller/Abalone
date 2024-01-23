#include "gui/mainwindow.h"
#include "controller/Controller.h"
#include "controller/controllergui.h"
#include "model/Game.h"
#include "view/View.h"

#include <QApplication>
#include <iostream>

#define RUN_TEST 2
//0 for run projet in the console,
//1 for run the tests, ne fonctionne pas
//2 for run the gui project

using namespace std;

#if RUN_TEST==0
int main()
{
    Game game{};
    Controller controller{& game, View{& game}};
    controller.initialise();
    controller.startGame();
}
//#elif RUN_TEST==1

//int main(int argc, char * const argv[])
//{
//    Catch::Session().run(argc, argv);
//}

#elif RUN_TEST==2

int main(int argc, char * argv[])
{
    QApplication a(argc, argv);

    Game observable{};
    ControllerGUI controller{& observable};
    controller.initialise();
    controller.getMainWindow()->show();

    return a.exec();
}

#endif



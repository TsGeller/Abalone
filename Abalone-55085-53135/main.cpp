#define CATCH_CONFIG_RUNNER
#include "test/catch.hpp"
#include "controller/Controller.h"
#include "model/Game.h"
#include "view/View.h"

//#include <QApplication>

#include <iostream>

#define RUN_TEST 0 //0 for run projet, 1 for test

using namespace std;

#if RUN_TEST==0
int main()
{
    Game game{};
    Controller controller{& game, View{& game}};
    controller.initialise();
    controller.startGame();
}
#else

int main(int argc, char * const argv[])
{
    Catch::Session().run(argc, argv);
}


#endif

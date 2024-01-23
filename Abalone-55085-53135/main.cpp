#define CATCH_CONFIG_RUNNER
#include "test/catch.hpp"
#include "controller/Controller.h"
#include "model/Game.h"
#include "view/View.h"

#include <iostream>

#define RUN_TEST 1 //1 for run projet, 0 for test

using namespace std;

#if RUN_TEST==1
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

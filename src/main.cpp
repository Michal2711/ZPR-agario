#include <iostream>
#include "../include/Ball.h"
#include "../include/Board.h"
#include "../include/Game.h"

int main()
{

    srand(static_cast<unsigned>(time(0)));

    Game game;

    game.run();

    return 0;
}
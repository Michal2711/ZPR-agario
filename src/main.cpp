#include "../include/Game.hpp"
#include <iostream>

int main()
{

    srand(static_cast<unsigned>(time(0)));

    Game game;
    std::cout<<game.getPlayer().getPosition().x<<std::endl;
    std::cout<<game.getPlayer().getPosition().y<<std::endl;
    while (game.running())
    {
        game.update();
        game.render();
    }

    return 0;
}
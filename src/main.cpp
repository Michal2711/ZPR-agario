#include "../include/Game.hpp"
#include <iostream>

int main()
{

    srand(static_cast<unsigned>(time(0)));
    // sf::Clock clock;

    Game game;
    std::cout<<game.getPlayer().getShape().getPosition().x<<std::endl;
    std::cout<<game.getPlayer().getShape().getPosition().y<<std::endl;
    while (game.running())
    {
        // float dt = clock.restart().asSeconds();
        game.update();
        game.render();
    }

    return 0;
}
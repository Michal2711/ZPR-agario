#include "../include/Game.hpp"
#include <iostream>

int main()
{

    srand(static_cast<unsigned>(time(0)));
    sf::Clock clock;
    const sf::Time timePerFrame = sf::seconds(1.f/60.f); // 60 klatek na sekundę

    Game game;
    std::cout<<game.getPlayer().getShape().getPosition().x<<std::endl;
    std::cout<<game.getPlayer().getShape().getPosition().y<<std::endl;
    while (game.running())
    {
        game.update();
        game.render();
    }

    return 0;
}
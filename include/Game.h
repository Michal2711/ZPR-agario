#pragma once

#include "../include/Ball.h"
#include "../include/Board.h"
#include "../include/Player.h"

class Game
{
private:
    Board board;
    Ball ball;
    Player player;
    // std::vector<Player> player_vec;
    Player player2;
    sf::Vector2f get_player_speed();
    sf::Clock clock;

public:
    Game();
    ~Game() = default;
    void run();
    void move_player();
    sf::Vector2f adjust_to_bounds(sf::Vector2f speed);
};
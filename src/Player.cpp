#include "../include/Player.h"
#include <iostream>

void Player::init_shape(sf::Vector2f position)
{
    auto ball = std::make_shared<Ball>(position);
    this->balls.push_back(ball);
};

void Player::print_balls()
{
    for (auto &ball : this->balls)
    {
        std::cout << ball->get_position().x << std::endl;
    }
};

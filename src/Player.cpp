#include "../include/Player.h"
#include <iostream>

void Player::add_ball(sf::Vector2f position, float size)
{
    std::cout << "TWORZENIE" << std::endl;
    Ball ball = Ball(position, size);
    this->balls.push_back(ball);
};

void Player::print_balls()
{
    for (auto ball : this->balls)
    {
        std::cout << ball.get_position().x << ":" << ball.get_position().y << std::endl;
    }
};

std::vector<Ball> &Player::get_balls()
{
    return this->balls;
};

#include "../include/Player.h"

void Player::add_ball(sf::Vector2f position, float size)
{
    Ball ball = Ball(position, size);
    this->balls.push_back(ball);
};

std::vector<Ball> &Player::get_balls()
{
    return this->balls;
};

float Player::get_shooting_range()
{
    return this->shooting_range;
}
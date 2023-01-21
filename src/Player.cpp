#include "../include/Player.h"

Player::Player()
{
    this->size = 10.f;
    this->position = sf::Vector2f(250.f, 250.f);
    this->color = sf::Color::Blue;
    this->speed = 50.f;
    this->init_shape(this->position, this->size, this->color);
};

float Player::get_speed()
{
    return this->speed;
};
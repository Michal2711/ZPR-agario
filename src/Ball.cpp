#include "../include/Ball.h"
#include <iostream>

void Ball::init_shape(sf::Vector2f position, float size, sf::Color color)
{
    this->shape.setPosition(position);
    this->shape.setRadius(size);
    this->shape.setFillColor(color);
    this->shape.setOrigin(this->size / 2.0f, this->size / 2.0f);
};

void Ball::set_color(sf::Color color)
{
    this->shape.setFillColor(color);
};

sf::CircleShape Ball::get_shape() const
{
    return this->shape;
};

void Ball::move(sf::Vector2f speed)
{
    this->shape.move(speed);
};

sf::Vector2f Ball::get_position()
{
    return this->shape.getPosition();
};

float Ball::get_size()
{
    return this->size;
};

void Ball::set_position(sf::Vector2f position)
{
    this->shape.setPosition(position);
};

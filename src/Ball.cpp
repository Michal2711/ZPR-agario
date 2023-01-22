#include "../include/Ball.h"
#include <iostream>

Ball::Ball(sf::Vector2f position, sf::Color color)
{
    this->init_shape(position, this->size, color);
};

void Ball::init_shape(sf::Vector2f position, float size, sf::Color color)
{
    this->shape.setPosition(position);
    this->shape.setRadius(size);
    this->shape.setFillColor(color);
    this->shape.setOrigin(this->size, this->size);
};

void Ball::set_color(sf::Color color)
{
    this->shape.setFillColor(color);
}

void Ball::set_speed(float new_speed)
{
    this->speed = new_speed;
}

void Ball::set_size(float new_size)
{
    this->size = new_size;
    this->shape.setRadius(new_size);
    this->shape.setOrigin(this->size, this->size);
}

sf::CircleShape Ball::get_shape() const
{
    return this->shape;
};

float Ball::get_speed() const
{
    return this->speed;
}

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

// b2Body* Ball::getBody() const
// {
//     return this->body;
// }

void Ball::set_position(sf::Vector2f position)
{
    this->shape.setPosition(position);
};

float Ball::get_speed()
{
    return this->speed;
};
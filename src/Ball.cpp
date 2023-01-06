#include "../include/Ball.hpp"

void Ball::initShape(const sf::RenderWindow& window)
{
    sf::Color color;
    color = sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
    this->shape.setRadius(this->size);
    this->shape.setFillColor(color);
    this->shape.setPosition(
        sf::Vector2f(
            static_cast<float>(rand() % window.getSize().x - this->shape.getGlobalBounds().width),
            static_cast<float>(rand() % window.getSize().y - this->shape.getGlobalBounds().height)
        )
    );
}

Ball::Ball(const sf::RenderWindow& window)
{
    this->initShape(window);
}

sf::CircleShape Ball::getShape() const
{
    return this->shape;
}

float Ball::getSize() const
{
    return this->size;
}

void Ball::update()
{

}

void Ball::render(sf::RenderTarget& target)
{
    target.draw(this->shape);
}
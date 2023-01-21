#include "../include/Player.h"
#include <iostream>
#include <cmath>

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

void Player::move(const sf::Vector2i& mousePos, float dt, const sf::RenderWindow* window)
{
    sf::Vector2f direction = sf::Vector2f(mousePos) - this->shape.getPosition();

    // std::cout<<"radius: "<<this->shape.getGlobalBounds().width<<std::endl;
    std::cout<<shape.getPosition().x<<"\t"<<shape.getPosition().y<<std::endl;

    dt = clock.restart().asSeconds();

    if(abs(direction.x) > 1.f && abs(direction.y) > 1.f){

        float distance = sqrt(direction.x * direction.x + direction.y * direction.y);

        direction = direction / distance;
        this->velocity = direction * this->speed;

        this->shape.move(this->velocity * dt);
    }

    // Ograniczenie, żeby kulka nie wychodziła poza obszar mapy
    sf::Vector2f position = this->shape.getPosition();
    if ( position.x < this->shape.getRadius() )
        position.x = this->shape.getRadius();
    else if ( position.x > window->getSize().x - shape.getRadius())
    if (position.x < this->shape.getRadius())
    {
        position.x = this->shape.getRadius();
    }
    else if (position.x > window->getSize().x - this->shape.getRadius())
    {
        position.x = window->getSize().x - this->shape.getRadius();
    }

    if (position.y < this->shape.getRadius())
    {
        position.y = this->shape.getRadius();
    }
    else if (position.y > window->getSize().y - this->shape.getRadius())
    {
        position.y = window->getSize().y - this->shape.getRadius();
    }

    this->shape.setPosition(position);

}
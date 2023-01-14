#include "../include/Player.hpp"
#include <iostream>
#include <cmath>


void Player::initShape()
{
    this->shape.setRadius(this->size);
    this->shape.setOrigin(this->size, this->size);
    this->shape.setFillColor(sf::Color::Blue);
}

void Player::setSize(const float& new_size)
{
    this->size = new_size;
    this->shape.setRadius(this->size);
}

void Player::setSpeed(const float& new_speed)
{
    this->speed = new_speed;
}

// void Player::setPosition(const sf::Vector2f& new_position){
//     this->position = new_position;
// }

// float Player::getSize() const
// {
//     return this->size;
// }

float Player::getSpeed() const
{
    return this->speed;
}

// sf::Vector2f Player::getPosition() const {
//     return this->position;
// }

// sf::CircleShape Player::getShape() const
// {
//    return this->shape;
// }

Player::Player()
{
    this->size = 10.f;
    this->initShape();
}

void Player::setDefault(sf::Vector2f position){
    this->position = position;
    this->speed = 200.f;
    this->shape.setPosition(position.x, position.y);
}

void Player::updateInput(const sf::Vector2i& mousePos, float dt, const sf::RenderWindow* window)
{
    sf::Vector2f direction = sf::Vector2f(mousePos) - this->shape.getPosition();

    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);

    direction = direction / distance;
    this->velocity = direction * this->speed;

    this->shape.move(this->velocity * dt);

    // Ograniczenie, żeby kulka nie wychodziła poza obszar mapy
    sf::Vector2f position = this->shape.getPosition();
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

    // std::cout<<this->getShape().getPosition().x<<std::endl;
    // std::cout<<this->getShape().getPosition().y<<std::endl;

    // this->shape.setPosition((float)mousePos.x, (float)mousePos.y);

    // if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    // {
    //     this->shape.move(-this->speed, 0.f);
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    // {
    //     this->shape.move(this->speed, 0.f);
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    // {
    //     this->shape.move(0.f, -this->speed);
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    // {
    //     this->shape.move(0.f, this->speed);
    // }
}

void Player::updateCollision(const sf::RenderTarget* target)
{
    // Left
    if(this->shape.getGlobalBounds().left <= 0.f)
        this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);
    // Right
    if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x)
		this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top);
	// Top
	if (this->shape.getGlobalBounds().top <= 0.f)
		this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);
	// Bottom
	if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y)
		this->shape.setPosition(this->shape.getGlobalBounds().left, target->getSize().y - this->shape.getGlobalBounds().height);
}

void Player::update(const sf::RenderTarget* target, const sf::RenderWindow* window)
{
    float dt = clock.restart().asSeconds();
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    this->updateInput(mousePos, dt, window);
    this->updateCollision(target);
}

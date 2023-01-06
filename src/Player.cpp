#include "../include/Player.hpp"
#include<iostream>


void Player::initShape()
{
    this->shape.setRadius(this->size);
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

void Player::setPosition(const sf::Vector2f& new_position){
    this->position = new_position;
}

// float Player::getSize() const
// {
//     return this->size;
// }

float Player::getSpeed() const
{
    return this->speed;
}

sf::Vector2f Player::getPosition() const {
    return this->position;
}

// sf::CircleShape Player::getShape() const
// {
//    return this->shape;
// }

Player::Player()
{
    this->size = 5.f;
    this->initShape();
}

void Player::setDefault(sf::Vector2f position){
    this->position = position;
    this->speed = 3.f;
    this->shape.setPosition(position.x, position.y);
}

void Player::updateInput()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->shape.move(-this->speed, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->shape.move(this->speed, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->shape.move(0.f, -this->speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->shape.move(0.f, this->speed);
    }
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

void Player::update(const sf::RenderTarget* target)
{
    this->updateInput();
    this->updateCollision(target);
}

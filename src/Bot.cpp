#include "../include/Bot.hpp"

void Bot::updateInput()
{
    while (true)
    {
        this->shape.move(-this->speed, 0.f);
        this->shape.move(this->speed, 0.f);
        this->shape.move(0.f, -this->speed);
        this->shape.move(0.f, this->speed);
    }
}

void Bot::update(const sf::RenderTarget *target)
{
    // switch (this->position)
    // {
    // case 0:
    //     this->shape.move(-this->speed, 0.f);
    //     break;
    // case 1:
    //     this->shape.move(this->speed, 0.f);
    //     break;

    // case 2:
    //     this->shape.move(0.f, -this->speed);
    //     break;
    // case 3:
    //     this->shape.move(0.f, this->speed);
    //     break;
    // default:
    //     break;
    // }
    // this->counter = this->counter + 1;
    // this->counter = this->counter % 10;
    // if (this->counter == 0)
    // {
    //     this->position = this->position + 1;
    //     this->position = this->position % 4;
    // }
    this->updateCollision(target);
}

void Bot::setColor(sf::Color color)
{
    this->shape.setFillColor(color);
}
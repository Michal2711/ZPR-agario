#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "../include/Ball.h"

class Player : public Ball
{
protected:
    sf::Vector2f position;
    float speed;
    sf::Color color;

public:
    Player();
    virtual ~Player() = default;
    float get_speed();
};
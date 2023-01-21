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
    sf::Vector2f velocity;
    sf::Clock clock;

public:
    Player();
    virtual ~Player() = default;
    float get_speed();
    void move(const sf::Vector2i& mousePos, float dt, const sf::RenderWindow* window);
};
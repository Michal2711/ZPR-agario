#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include "../include/Ball.h"

class Player
{
protected:
    std::vector<Ball> balls;

public:
    Player() = default;
    void add_ball(sf::Vector2f position);
    void print_balls();
    std::vector<Ball> &get_balls();
    virtual ~Player() = default;
};
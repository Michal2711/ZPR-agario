#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include "../include/Ball.h"

const float SHOUTING_RANGE = 4.f;

class Player
{
protected:
    std::vector<Ball> balls;
    float shooting_range = SHOUTING_RANGE;

public:
    Player() = default;
    void add_ball(sf::Vector2f position, float size);
    // void print_balls();
    float get_shooting_range();
    std::vector<Ball> &get_balls();
    virtual ~Player() = default;
};
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include "../include/Ball.h"

class Player
{
protected:
    std::vector<std::shared_ptr<Ball>> balls;

public:
    Player() = default;
    void init_shape(sf::Vector2f position);
    void print_balls();
    virtual ~Player() = default;
};
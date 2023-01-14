#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "../include/Ball.hpp"
#include "../include/Player.hpp"

class Bot : public Player
{
private:
    void updateInput();
    int position = 0;
    int counter = 0;

public:
    void update(const sf::RenderTarget *target);
    void setColor(sf::Color color);
};
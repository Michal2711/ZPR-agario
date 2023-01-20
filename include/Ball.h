#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Ball
{
protected:
    sf::CircleShape shape;
    float size;

public:
    Ball() = default;
    virtual ~Ball() = default;
    void init_shape(sf::Vector2f position, float size, sf::Color color = sf::Color::Red);

    void set_color(sf::Color color);

    sf::CircleShape get_shape() const;
    void move(sf::Vector2f speed);
    sf::Vector2f get_position();
    float get_size();
    void set_position(sf::Vector2f position);
};
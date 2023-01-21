#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Ball
{
protected:
    // zmienic by byly zmienne globalne
    float size = 10.f;
    float speed = 50.f;
    sf::CircleShape shape;
    sf::Color color;

public:
    Ball() = default;
    Ball(sf::Vector2f position, sf::Color color = sf::Color::Blue);
    virtual ~Ball() = default;
    void init_shape(sf::Vector2f position, float size, sf::Color color = sf::Color::Red);

    void set_color(sf::Color color);

    sf::CircleShape get_shape() const;
    void move(sf::Vector2f speed);
    sf::Vector2f get_position();
    float get_size();
    void set_position(sf::Vector2f position);
    float get_speed();
};
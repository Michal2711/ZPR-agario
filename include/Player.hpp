#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "../include/Ball.hpp"

class Player : public Ball
{
    private:
        // sf::CircleShape shape;
        // float size=5.f;
        sf::Vector2f position;
        sf::Vector2f velocity;
        float speed=200.f;
        sf::Clock clock;

    void initShape();

public:
    Player();
    virtual ~Player() = default;

        // sf::CircleShape getShape() const;
        // float getSize() const;
        void setDefault(sf::Vector2f position);
        float getSpeed() const;
        // sf::Vector2f getPosition() const;
        void setSize(const float& new_size);
        void setSpeed(const float& new_speed);
        // void setPosition(const sf::Vector2f& new_position);

        void updateInput(const sf::Vector2i& mousePos, float dt, const sf::RenderWindow* window);
        void updateCollision(const sf::RenderTarget* target);
        void update(const sf::RenderTarget* target, const sf::RenderWindow* window);
};
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Ball{
    protected:
        sf::CircleShape shape;
        float size=3.f;

        void initShape(const sf::RenderWindow& widnow);

    public:
        Ball()=default;
        Ball(const sf::RenderWindow& window);
        virtual ~Ball() = default;

        sf::CircleShape getShape() const;
        float getSize() const;

        void update();
        void render(sf::RenderTarget& target);
};
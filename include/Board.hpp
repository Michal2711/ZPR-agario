// #include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Board {
    private:
        const int columns = 100;
        const int rows = 100;
        const int cell_size = 7;
        const int numLines = rows + columns - 2;
        const int window_size_x = 600; // 800
        const int window_size_y = 600; // 600
        const int zoom = 2;
        const int board_texture_size = 2000;

        sf::VideoMode videoMode;
        sf::RenderWindow* window;
        sf::VertexArray grid;
        sf::Texture board_texture;
        sf::Sprite board_sprite;
        sf::Vector2f player_position;

    public:
        Board() = default;
        ~Board() = default;
        sf::View view;
        void createBoard();
        void setPlayerPositionX(const float value);
        void setPlayerPositionY(const float value);
        void setHorizontalCoordinates(float rowH, sf::Vector2f size);
        void setVerticalCoordinates(float colW, sf::Vector2f size);
        void setGridColor();

        sf::VideoMode getVideoMode() const;
        sf::RenderWindow* getWindow() const;
        sf::View const& getView() const;
        sf::Vector2f getPlayerPosition() const;
        sf::Sprite getBoardSprite() const;
        sf::VertexArray getGrid() const;
};
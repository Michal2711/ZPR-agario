#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
#include "Player.h"

class Board
{
private:
    const float bound = 200.f;
    const int window_size_x = 800;
    const int window_size_y = 600;

    sf::Vector2f bounds_pos = sf::Vector2f((window_size_x / 2) - (bound / 2), (window_size_y / 2) - (bound / 2));
    sf::Vector2f bounds_size = sf::Vector2f(bound, bound);
    sf::FloatRect bounds = sf::FloatRect(bounds_pos, bounds_size);



    sf::VideoMode video_mode;
    sf::RenderWindow *window;

    sf::View view;
    sf::Vector2f player_pos;

    sf::Event sfmlEvent;

    sf::RectangleShape grid;
    sf::VertexArray grid_lines;
    const int cell_size = 10;

    const int zoom = 2;

public:
    Board() = default;
    ~Board() = default;
    void createBoard();
    void checkClosed();
    const bool is_running() const;
    void render(Player palyer);
    void draw_player(Player player);
    void draw_grid();
    void draw_grid_lines();
    void create_grid_lines();
    void set_player_pos(sf::Vector2f new_pos);
    sf::FloatRect get_bounds();
    sf::VertexArray getGrid() const;
    sf::Vector2i get_mouse_pos();

};
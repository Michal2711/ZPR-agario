#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
// #include "Player.h"
#include "Ball.h"
#include <vector>

class Board
{
private:
    const float bound = 1000.f;
    const int window_size_x = 500;
    const int window_size_y = 500;
    // sf::Vector2f view_center;

    sf::Vector2f bounds_pos = sf::Vector2f((window_size_x / 2) - (bound / 2), (window_size_y / 2) - (bound / 2));
    sf::Vector2f bounds_size = sf::Vector2f(bound, bound);
    sf::FloatRect bounds = sf::FloatRect(bounds_pos, bounds_size);

    sf::VideoMode video_mode;
    sf::RenderWindow *window;

    sf::View view;

    // delete this
    sf::Vector2f player_pos;
    sf::Vector2f player_origin = sf::Vector2f(0.f, 0.f);

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
    void render(Ball palyer, Ball player2, std::unordered_map<int, std::unordered_map<int, std::vector<Ball>>> net);
    void draw_static_balls();
    void draw_player(Ball player);
    void draw_ball(Ball ball);
    void draw_grid();
    void draw_grid_lines();
    void create_grid_lines();
    void set_player_pos(sf::Vector2f new_pos);
    // void set_count_balls(int new_count);
    sf::FloatRect get_bounds();
    sf::VertexArray getGrid() const;
    sf::Vector2f get_mouse_pos();
    sf::Vector2f get_window_centre();
    sf::Vector2f get_view_centre();
    sf::RenderWindow* get_window() const;
    sf::Vector2u get_bound() const;
    void update_player_origin(sf::Vector2f player_move);
};
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
#include "Player.h"
#include <unordered_map>
#include <vector>
// #include "Ball.h"

const float BOUND = 2000.f;
const int WINDOW_X = 500;
const int WINDOW_Y = 500;
const int CELL_SIZE = 10;


class Board
{
private:
    const float bound = BOUND;
    const int window_size_x = WINDOW_X;
    const int window_size_y = WINDOW_Y;

    sf::Vector2f bounds_pos = sf::Vector2f((window_size_x / 2) - (bound / 2), (window_size_y / 2) - (bound / 2));
    sf::Vector2f bounds_size = sf::Vector2f(bound, bound);
    sf::FloatRect bounds = sf::FloatRect(bounds_pos, bounds_size);

    sf::VideoMode video_mode;
    sf::RenderWindow *window;

    sf::View view;

    sf::Event sfmlEvent;

    sf::RectangleShape grid;
    sf::VertexArray grid_lines;
    const int cell_size = CELL_SIZE;
public:
    Board() = default;
    ~Board() = default;
    void createBoard();
    void checkClosed();
    const bool is_running() const;
    void render(std::vector<Ball> balls, std::vector<Player> bots, std::unordered_map<int, std::unordered_map<int, std::vector<Ball>>> net);
    void draw_player(std::vector<Ball> balls);
    // void draw_static_balls();
    void draw_ball(Ball ball);
    void draw_grid();
    void draw_grid_lines();
    void create_grid_lines();
    void update_view(std::vector<Ball> balls);
    sf::FloatRect get_bounds();
    sf::VertexArray getGrid() const;
    sf::Vector2f get_mouse_pos();
    sf::Vector2f get_window_size();
    sf::Vector2f get_window_centre();
    sf::Vector2f get_view_centre();
    sf::RenderWindow *get_window() const;
    sf::Vector2u get_bound() const;
};
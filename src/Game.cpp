#include "../include/Game.h"
#include <cmath>

// remove later
#include <iostream>

Game::Game()
{
    this->board.createBoard();
};

sf::Vector2f Game::get_player_speed()
{
    float dt = this->clock.restart().asSeconds();
    sf::Vector2f direction = sf::Vector2f(this->board.get_mouse_pos()) - this->player.get_position();
    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
    direction = direction / distance;
    direction = direction * player.get_speed();
    return this->adjust_to_bounds(direction * dt);
};

void Game::run()
{
    clock.restart();
    while (this->board.is_running())
    {
        this->move_player();
        this->board.render(this->player);
    }
};

void Game::move_player()
{
    sf::Vector2f speed = this->get_player_speed();

    this->player.move(speed);
    std::cout << this->player.get_position().x << ":" << this->player.get_position().y << std::endl;
    this->board.set_player_pos(this->player.get_position());
};

sf::Vector2f Game::adjust_to_bounds(sf::Vector2f speed)
{
    sf::FloatRect player = this->player.get_shape().getGlobalBounds();
    sf::FloatRect board = this->board.get_bounds();

    // float player_top = player_bounds.top;
    // float player_bottom = player_bounds.top + player_bounds.height;
    // float player_left = player_bounds.left;
    // float player_right = player_bounds.left + player_bounds.width;
    // float player_width = player_bounds.width;

    // float board_top = board_bounds.top;
    // float board_bottom = board_bounds.top + board_bounds.height;
    // float board_left = board_bounds.left;
    // float board_right = board_bounds.left + board_bounds.width;

    if ((player.top + speed.y < board.top) || ((player.top + player.height) + speed.y > (board.top + board.height)))
        speed.y = 0.f;
    if ((player.left + speed.x < board.left) || ((player.left + player.width) + speed.x > (board.left + board.width)))
        speed.x = 0.f;

    std::cout << "predkosc:" << speed.x << " " << speed.y << std::endl;
    return speed;
};

#include "../include/Game.h"
#include <cmath>

// remove later
#include <iostream>

Game::Game()
{
    this->board.createBoard();
    this->player_best.add_ball(this->board.get_window_centre());
    this->player_best.add_ball(sf::Vector2f(300.f, 300.f));
    this->player_best.add_ball(sf::Vector2f(350.f, 350.f));
    this->player_best.add_ball(sf::Vector2f(350.f, 400.f));
    this->player_best.add_ball(sf::Vector2f(350.f, 450.f));
};

void normalize_vector(sf::Vector2f &direction)
{
    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (distance)
        direction = direction / distance;
    else
        direction = sf::Vector2f(0, 0);
};

sf::Vector2f Game::calculate_velocity(sf::Vector2f position, float speed)
{
    // float dt = this->clock.restart().asSeconds();
    float dt = 0.016f;

    sf::Vector2f window_size = this->board.get_window_size();
    window_size.x /= 2;
    window_size.y /= 2;

    sf::Vector2f direction = this->board.get_view_centre() - window_size;
    direction += this->board.get_mouse_pos() - position;

    normalize_vector(direction);

    return direction * speed * dt;
};

void Game::run()
{
    clock.restart();
    while (this->board.is_running())
    {
        this->move_player();
        this->board.render(this->player_best.get_balls()); // this should take vector of players
    }
};

void Game::move_player()
{
    for (auto &ball : player_best.get_balls())
    {
        sf::Vector2f velocity = this->calculate_velocity(ball.get_position(), ball.get_speed());
        velocity = adjust_to_bounds(velocity, ball.get_shape().getGlobalBounds());
        ball.move(velocity);
    }
};

sf::Vector2f Game::adjust_to_bounds(sf::Vector2f velocity, sf::FloatRect ball_bounds)
{
    sf::FloatRect board_bounds = this->board.get_bounds();

    if ((ball_bounds.top + velocity.y < board_bounds.top) || ((ball_bounds.top + ball_bounds.height) + velocity.y > (board_bounds.top + board_bounds.height)))
        velocity.y = 0.f;
    if ((ball_bounds.left + velocity.x < board_bounds.left) || ((ball_bounds.left + ball_bounds.width) + velocity.x > (board_bounds.left + board_bounds.width)))
        velocity.x = 0.f;
    return velocity;
};

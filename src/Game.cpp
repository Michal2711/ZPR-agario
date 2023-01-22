#include "../include/Game.h"
#include <cmath>

// remove later
#include <iostream>

Game::Game()
{
    this->board.createBoard();
    this->player_best.init_shape(this->board.get_window_centre());
    player_best.print_balls(); // this prints
};

sf::Vector2f Game::get_player_speed()
{
    float dt = this->clock.restart().asSeconds();

    sf::Vector2f direction = this->board.get_view_centre() - sf::Vector2f(250.f, 250.f); // chyba zadziala ale nie wiem czy nie trza dodac
    direction += this->board.get_mouse_pos();
    direction -= this->player.get_position();

    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (distance)
        direction = direction / (distance);
    else
        direction = sf::Vector2f(0, 0);

    direction = direction * player.get_speed();
    return this->adjust_to_bounds(direction * dt);
};

void Game::run()
{
    clock.restart();
    while (this->board.is_running())
    {
        this->move_player();
        this->spawnBalls();
        this->board.render(this->player, this->player2, this->net); // this should take vector of players
    }
};

void Game::move_player()
{
    sf::Vector2f speed = this->get_player_speed();

    this->player.move(speed);
    // std::cout << speed.x << ":" << speed.y << std::endl;
    this->board.update_player_origin(speed);
    // std::cout << this->player.get_position().x << ":" << this->player.get_position().y << std::endl;
    this->board.set_player_pos(this->player.get_position());
};

sf::Vector2f Game::adjust_to_bounds(sf::Vector2f speed)
{
    sf::FloatRect player = this->player.get_shape().getGlobalBounds();
    sf::FloatRect board = this->board.get_bounds();

    if ((player.top + speed.y < board.top) || ((player.top + player.height) + speed.y > (board.top + board.height)))
        speed.y = 0.f;
    if ((player.left + speed.x < board.left) || ((player.left + player.width) + speed.x > (board.left + board.width)))
        speed.x = 0.f;

    // std::cout << "predkosc:" << speed.x << " " << speed.y << std::endl;
    return speed;
};

void Game::spawnBalls()
{
    if (this->spawn_time < this->max_spawn_time)
        this -> spawn_time += 1.f;
    else
    {
        if ( this->count_balls < this->max_balls)
        {
            sf::Color color;
            sf::Vector2f position;
            for ( int i = 0; i < this->max_balls; ++i){
                color = sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
                position = sf::Vector2f(
                    static_cast<float>(rand() % this->board.get_bound().x),
                    static_cast<float>(rand() % this->board.get_bound().y)
                );
            }
            int netX = position.x / this->net_size;
            int netY = position.y / this->net_size;
            Ball ball(position, color);
            this->net[netX][netY].push_back(Ball(position, color));
            this->count_balls += 1;
            this->spawn_time = 0.f;
        }
    }
}

// void Game::checkCollision()
// {

//     for (Ball ball: this->player.get_balls() )
//     int startX = std::max(0, (this->player.get_position().x - this->player.getradius) / GRID_SIZE);
//     int endX = std::min(GRID_WIDTH - 1, (playerX + radius) / GRID_SIZE);
//     int startY = std::max(0, (playerY - radius) / GRID_SIZE);
//     int endY = std::min(GRID_HEIGHT - 1, (playerY + radius) / GRID_SIZE);

//     for (int x = startX; x <= endX; ++x)
//     {
//         for (int y = startY; y <= endY; ++y)
//         {
//             auto& cell = grid[x][y];
//             for (auto obj1 : cell)
//             {
//                 for (auto obj2 : cell)
//                 {
//                     if (obj1 == obj2)
//                         continue;
//                     if (obj1->x < obj2->x + obj2->w &&
//                         obj1->x + obj1->w > obj2->x &&
//                         obj1->y < obj2->y + obj2->h &&
//                         obj1->h + obj1->y > obj2->y)
//                     {
//                         // Kolizja została wykryta, wykonaj odpowiednie działanie
//                         //...
//                     }
//                 }
//             }
//         }
//     }
// }
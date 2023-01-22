#include "../include/Game.h"
#include <cmath>

// remove later
#include <iostream>
#include <Box2/Box2D.h>

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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            this->splitBalls();
        }
        this->move_player();
        this->spawnBalls();
        this->checkJoin();
        this->checkCollision();
        this->board.render(this->player_best.get_balls(), this->net); // this should take vector of players
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

void Game::spawnBalls()
{
    if (this->spawn_time < this->max_spawn_time)
        this->spawn_time += 1.f;
    else
    {
        if (this->count_balls < this->max_balls)
        {
            sf::Color color;
            sf::Vector2f position;
            for (int i = 0; i < this->max_balls; ++i)
            {
                color = sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
                position = sf::Vector2f(
                    static_cast<float>(rand() % this->board.get_bound().x),
                    static_cast<float>(rand() % this->board.get_bound().y));
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

void Game::checkCollision()
{
    for( auto& ball: this->player_best.get_balls()){
        int startX = std::max(0, (int(ball.get_position().x - ball.get_size())) / this->net_size);
        int endX = std::min(this->net_width - 1, int(ball.get_position().x + ball.get_size()) / this->net_size);
        int startY = std::max(0, (int(ball.get_position().y - ball.get_size())) / this->net_size);
        int endY = std::min(this->net_height - 1, (int(ball.get_position().y + ball.get_size())) / this->net_size);

        for (int x = startX; x <= endX; ++x)
        {
            for (int y = startY; y <= endY; ++y)
            {
                auto& cell = this->net[x][y];
                for (size_t i = 0; i < cell.size(); ++i)
                {
                    if(ball.get_shape().getGlobalBounds().intersects(cell[i].get_shape().getGlobalBounds()))
                    {
                        cell.erase(cell.begin() + i);
                    }
                }
            }
        }

    }
}

void Game::checkJoin()
{
    for( size_t i = 0; i < this->player_best.get_balls().size(); ++i){
        for( size_t j = i + 1 ; j < this->player_best.get_balls().size(); ++j){
            if((this->player_best.get_balls()[i].get_shape().getGlobalBounds().contains(this->player_best.get_balls()[j].get_position())) || (this->player_best.get_balls()[j].get_shape().getGlobalBounds().contains(this->player_best.get_balls()[i].get_position())))
            {
            // if(sqrt(pow(this->player_best.get_balls()[i].get_position().x - this->player_best.get_balls()[j].get_position().x, 2) + pow(this->player_best.get_balls()[i].get_position().y - this->player_best.get_balls()[j].get_position().y, 2)) < 5.0f){
                if ( this->player_best.get_balls()[i].get_size() >= this->player_best.get_balls()[j].get_size()){
                    this->player_best.get_balls()[i].set_size(this->player_best.get_balls()[i].get_size() + this->player_best.get_balls()[j].get_size()/2);
                    this->player_best.get_balls().erase(this->player_best.get_balls().begin() + j);
                }
                else {
                    this->player_best.get_balls()[j].set_size(this->player_best.get_balls()[j].get_size() + this->player_best.get_balls()[i].get_size()/2);
                    this->player_best.get_balls().erase(this->player_best.get_balls().begin() + i);
                }
            }
        }
    }
}

void Game::splitBalls()
{
    std::cout<<"BARCELONA"<<std::endl;
    int size_before = this->player_best.get_balls().size();
    for ( size_t i = 0; i < size_before; ++i){
        sf::Vector2f direction = this->calculate_velocity(this->player_best.get_balls()[i].get_position(), this->player_best.get_balls()[i].get_speed());
        sf::Vector2f newPosition = this->player_best.get_balls()[i].get_position() + direction;
        Ball childBall(newPosition);
        childBall.set_speed(childBall.get_size()/2);
        b2Vec2 impuls = b2Vec(direction.x * this->player_best.get_balls()[i].get_size(), direction.y * this->player_best.get_balls()[i].get_size());
        childBall.getBody()->ApplylinearImpulse(impulse, childeBall.getBody()->GetWorldCenter(), true);
        this->player_best.add_ball(childBall);
        this->player_best.get_balls()[i].set_size(this->player_best.get_balls()[i].set_size/2)
    }
}

#include "../include/Game.h"
#include <cmath>

#include <iostream>

Game::Game()
{
    this->board.createBoard();
    this->player_best.add_ball(this->board.get_window_centre(), 10.f);
    this->player_best.add_ball(sf::Vector2f(200.f, 200.f), 10.f);
    this->player_best.add_ball(sf::Vector2f(400.f, 200.f), 10.f);
    this->player_best.add_ball(sf::Vector2f(200.f, 400.f), 10.f);
    this->bots.push_back(Player());
    bots.front().add_ball(sf::Vector2f(600.f, 600.f), 10.f);
};

void normalize_vector(sf::Vector2f &direction)
{
    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (distance)
        direction = direction / distance;
    else
        direction = sf::Vector2f(0, 0);
};

int Game::get_count_balls() const
{
    return this->count_balls;
}

Player &Game::get_player_best()
{
    return this->player_best;
}

Board Game::get_board()
{
    return this->board;
}

int Game::get_max_balls() const
{
    return this->max_balls;
}

int Game::get_net_size() const
{
    return this->net_size;
}

void Game::set_max_balls(int new_max)
{
    this->max_balls = new_max;
}

void Game::set_count_balls(int new_count)
{
    this->count_balls = new_count;
}

void Game::push_to_net(Ball ball, int netX, int netY)
{
    this->net[netX][netY].push_back(ball);
}

sf::Vector2f Game::calculate_direction(sf::Vector2f position)
{
    sf::Vector2f window_center = this->board.get_window_size() / 2.f;

    sf::Vector2f direction = this->board.get_view_centre() - window_center;
    direction += this->board.get_mouse_pos() - position;

    normalize_vector(direction);
    return direction;
}

void Game::run()
{
    clock.restart();
    while (this->board.is_running())
    {
        this->checkDivision();
        this->move_player();
        this->move_bots();
        this->waitForSpawn();
        this->checkJoin();
        this->checkCollision();
        this->checkBounds();
        this->board.render(this->player_best.get_balls(), this->net);
    }
};

void Game::checkBounds()
{

    sf::FloatRect board_bounds = this->board.get_bounds();
    for (auto &ball : this->player_best.get_balls())
    {
        sf::Vector2f position = ball.get_position();
        sf::FloatRect ball_bounds = ball.get_shape().getGlobalBounds();
        if (ball_bounds.top < board_bounds.top)
            ball.set_position(sf::Vector2f(ball.get_position().x, board_bounds.top + 2 * ball.get_size()));
        else if ((ball_bounds.top + ball_bounds.height) > (board_bounds.top + board_bounds.height))
            ball.set_position(sf::Vector2f(ball.get_position().x, board_bounds.top + board_bounds.height - 2 * ball.get_size()));
        else if (ball_bounds.left < board_bounds.left)
            ball.set_position(sf::Vector2f(board_bounds.left + 2 * ball.get_size(), ball.get_position().y));
        else if ((ball_bounds.left + ball_bounds.width) > (board_bounds.left + board_bounds.width))
            ball.set_position(sf::Vector2f(board_bounds.left + board_bounds.width - 2 * ball.get_size(), ball.get_position().y));
    }
}

void Game::move_player()
{
    for (auto &ball : player_best.get_balls())
    {
        float dt = 0.016f;
        sf::Vector2f velocity = dt * ball.get_speed() * this->calculate_direction(ball.get_position());
        velocity = adjust_to_bounds(velocity, ball.get_shape().getGlobalBounds());
        ball.move(velocity);
    }
};

sf::Vector2f Game::calculate_direction_bot(sf::Vector2f position, sf::Vector2f destination)
{
    sf::Vector2f window_center = this->board.get_window_size() / 2.f;

    sf::Vector2f direction = this->board.get_view_centre() - window_center;
    direction += destination - position;

    normalize_vector(direction);
    return direction;
}

void Game::move_bots()
{
    for (auto bot : this->bots)
    {
        for (auto ball : bot.get_balls())
        {
            sf::Vector2f position = ball.get_position();

            sf::Vector2f direction = this->calculate_direction_bot(position, sf::Vector2f(0.f, 0.f));
        }
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

void Game::waitForSpawn()
{
    if (this->spawn_time < this->max_spawn_time)
        this->spawn_time += 1.f;
    else
    {
        this->spawnBalls();
    }
}

void Game::spawnBalls()
{
    sf::FloatRect board_bounds = this->board.get_bounds();
    if (this->count_balls < this->max_balls)
    {
        sf::Color color;
        sf::Vector2f position;
        for (int i = 0; i < this->max_balls; ++i)
        {
            color = sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
            position = sf::Vector2f(
                static_cast<float>(rand() % int(board_bounds.width) + board_bounds.left),
                static_cast<float>(rand() % int(board_bounds.height) + board_bounds.top));
        }
        int netX = position.x / this->net_size;
        int netY = position.y / this->net_size;
        Ball ball(position, 10.f, color);                             // change to have variable
        this->net[netX][netY].push_back(Ball(position, 10.f, color)); // change to have variable
        this->count_balls += 1;
        this->spawn_time = 0.f;
    }
}

float get_join_size(double size1, double size2)
{

    double area1 = size1 * size1;
    double area2 = size2 * size2;
    return float(sqrt(area1 + area2));
};

float get_division_size(double size)
{
    return float(sqrt((size * size) / 2.f));
}

void Game::checkCollision()
{
    sf::FloatRect board_bounds = this->board.get_bounds();
    for (auto &ball : this->player_best.get_balls())
    {
        int startX = std::max(int(board_bounds.left / this->net_size), (int(ball.get_position().x - ball.get_size())) / this->net_size);
        int endX = std::min(int(board_bounds.left + board_bounds.width) / this->net_size, int(ball.get_position().x + ball.get_size()) / this->net_size);
        int startY = std::max(int(board_bounds.top / this->net_size), (int(ball.get_position().y - ball.get_size())) / this->net_size);
        int endY = std::min(int(board_bounds.top + board_bounds.height) / this->net_size, (int(ball.get_position().y + ball.get_size())) / this->net_size);

        for (int x = startX; x <= endX; ++x)
        {
            for (int y = startY; y <= endY; ++y)
            {
                auto &cell = this->net[x][y];
                for (size_t i = 0; i < cell.size(); ++i)
                {
                    if (ball.get_shape().getGlobalBounds().intersects(cell[i].get_shape().getGlobalBounds()))
                    {
                        ball.set_size(get_join_size(ball.get_size(), cell[i].get_size()));
                        cell.erase(cell.begin() + i);
                        this->count_balls -= 1;
                    }
                }
            }
        }
    }
}

void Game::checkJoin()
{

    for (size_t i = 0; i < this->player_best.get_balls().size(); ++i)
    {
        for (size_t j = i + 1; j < this->player_best.get_balls().size(); ++j)
        {
            if ((this->player_best.get_balls()[i].get_shape().getGlobalBounds().contains(this->player_best.get_balls()[j].get_position())) || (this->player_best.get_balls()[j].get_shape().getGlobalBounds().contains(this->player_best.get_balls()[i].get_position())))
            {
                if (this->player_best.get_balls()[i].get_size() >= this->player_best.get_balls()[j].get_size())
                {
                    this->player_best.get_balls()[i].set_size(get_join_size(this->player_best.get_balls()[j].get_size(), this->player_best.get_balls()[i].get_size()));
                    this->player_best.get_balls().erase(this->player_best.get_balls().begin() + j);
                }
                else
                {
                    this->player_best.get_balls()[j].set_size(get_join_size(this->player_best.get_balls()[j].get_size(), this->player_best.get_balls()[i].get_size()));
                    this->player_best.get_balls().erase(this->player_best.get_balls().begin() + i);
                }
            }
        }
    }
}

void Game::checkDivision()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !this->space_pressed)
    {
        this->space_pressed = true;
        this->splitBalls();
    }
    else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        this->space_pressed = false;
    }
};

void Game::splitBalls()
{
    std::vector<Ball> &player_balls = this->player_best.get_balls();
    int size_before = player_balls.size();
    for (int i = 0; i < size_before; i++)
    {
        if (player_balls[i].get_size() < 10.f)
            continue;
        float size = get_division_size(player_balls[i].get_size());
        player_balls[i].set_size(size);
        sf::Vector2f velocity = this->calculate_direction(player_balls[i].get_position());
        velocity = adjust_to_bounds(velocity, player_balls[i].get_shape().getGlobalBounds());
        player_best.add_ball(player_balls[i].get_position() + velocity * player_best.get_shooting_range() * size, size);
    }
}

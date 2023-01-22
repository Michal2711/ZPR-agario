#pragma once

#include "../include/Ball.h"
#include "../include/Board.h"
#include "../include/Player.h"
#include <unordered_map>

class Game
{
private:
    Board board;
    Ball ball;
    Player player_best;
    Ball player = Ball(sf::Vector2f(300.f, 240.f));
    // std::vector<Player> player_vec;
    Ball player2 = Ball(sf::Vector2f(240.f, 300.f));
    sf::Vector2f get_player_speed();
    sf::Vector2f calculate_velocity(sf::Vector2f position, float speed);
    sf::Vector2f adjust_to_bounds(sf::Vector2f speed, sf::FloatRect ball_bounds);
    sf::Clock clock;

    const int net_size = 32;               // rozmiar komórki
    const int net_width = 800 / net_size;  // liczba komórek w poziomie
    const int net_height = 600 / net_size; // liczba komórek w pionie
    std::unordered_map<int, std::unordered_map<int, std::vector<Ball>>> net;

    const int max_balls = 100;
    int count_balls = 0;
    float max_spawn_time = 10.f;
    float spawn_time = 10.f;

public:
    Game();
    ~Game() = default;
    void run();
    void move_player();
    void spawnBalls();
    // void checkCollision();
    // void removeBall(Ball* ball);
};
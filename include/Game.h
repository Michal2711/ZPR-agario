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
    sf::Vector2f adjust_to_bounds(sf::Vector2f speed, sf::FloatRect ball_bounds);
    void checkBounds();
    sf::Clock clock;

    bool space_pressed = false;

    const int net_size = 32;                // rozmiar komórki
    const int net_width = 1000 / net_size;  // liczba komórek w poziomie
    const int net_height = 1000 / net_size; // liczba komórek w pionie
    std::unordered_map<int, std::unordered_map<int, std::vector<Ball>>> net;

    int max_balls = 1000;
    int count_balls = 0;
    float max_spawn_time = 10.f;
    float spawn_time = 10.f;

public:
    sf::Vector2f calculate_direction(sf::Vector2f position);
    Game();
    ~Game() = default;
    void run();
    void move_player();
    void waitForSpawn();
    void spawnBalls();
    void checkCollision();
    void checkJoin();
    void checkDivision();
    void splitBalls();
    Board get_board();
    int get_max_balls() const;
    int get_count_balls() const;
    int get_net_size() const;
    void set_max_balls(int new_max);
    void set_count_balls(int new_count);
    void push_to_net(Ball ball, int netX, int netY);
    sf::Vector2f calculate_velocity(sf::Vector2f position, float speed);
    Player &get_player_best();
};
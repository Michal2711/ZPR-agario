#pragma once

#include "../include/Ball.h"
#include "../include/Board.h"
#include "../include/Player.h"
#include <unordered_map>

const int NET_SIZE = 32;
const int NET_WIDTH = 1000 / NET_SIZE;
const int NET_HEIGHT = 1000 / NET_SIZE;
const int MAX_BALLS = 1000;
const float MAX_SPAWN_TIME = 10.f;

class Game
{
private:
    Board board;
    std::vector<Player> bots;
    Player player_best;
    sf::Vector2f adjust_to_bounds(sf::Vector2f speed, sf::FloatRect ball_bounds);
    void checkBounds();
    sf::Clock clock;

    bool space_pressed = false;

    const int net_size = NET_SIZE;                // rozmiar komórki
    const int net_width = NET_WIDTH;  // liczba komórek w poziomie
    const int net_height = NET_HEIGHT; // liczba komórek w pionie
    std::unordered_map<int, std::unordered_map<int, std::vector<Ball>>> net;

    int max_balls = MAX_BALLS;
    int count_balls = 0;
    float max_spawn_time = MAX_SPAWN_TIME;
    float spawn_time = MAX_SPAWN_TIME;

public:
    Game();
    ~Game() = default;
    sf::Vector2f calculate_direction(sf::Vector2f position);
    sf::Vector2f calculate_direction_bot(sf::Vector2f position, sf::Vector2f destination);
    void run();
    void move_player();
    void move_bots();
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
    Player &get_player_best();
};
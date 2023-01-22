#include <gtest/gtest.h>
#include "myfunctions.h"
#include "../include/Game.h"
// #include "../include/Ball.h"
// #include "../include/Board.h"
#include <cmath>

TEST(GameTest, OnlyOnePlayer)
{
    Game game;
    GTEST_ASSERT_EQ(game.get_player_best().get_balls().size(), 1);
}

TEST(PlayerTest, addBall)
{
    Game game;
    int before_adding = game.get_player_best().get_balls().size();
    game.get_player_best().add_ball(sf::Vector2f(200.f, 200.f), 10.f);
    int after_adding = game.get_player_best().get_balls().size();
    GTEST_ASSERT_EQ(after_adding, before_adding + 1);
}

// sprawdzanie czy zwracana jest referencja
TEST(GameTest, getPlayerBest) {
    Game game;
    Player& player_best = game.get_player_best();
    EXPECT_EQ(&player_best, &game.get_player_best());
}

TEST(GameTest, calculateVelocity) {
    Game game;
    sf::Vector2f position(100, 100);
    float speed = 50;
    sf::Vector2f velocity = game.calculate_velocity(position, speed);

    // calculate expected velocity manually
    sf::Vector2f window_size = game.get_board().get_window_size();
    window_size.x /= 2;
    window_size.y /= 2;
    sf::Vector2f direction = game.get_board().get_view_centre() - window_size;
    direction += game.get_board().get_mouse_pos() - position;
    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (distance)
        direction = direction / distance;
    else
        direction = sf::Vector2f(0, 0);
    sf::Vector2f expected_velocity = direction * speed * 0.016f;

    // Compare calculated velocity with expected velocity
    EXPECT_EQ(velocity, expected_velocity);
}

TEST(GameTest, playerMove)
{
    Game game;
    sf::Vector2f position_before_move = game.get_player_best().get_balls()[0].get_position();
    float player_speed = game.get_player_best().get_balls()[0].get_speed();
    sf::Vector2f velocity = game.calculate_velocity(position_before_move, player_speed);
    sf::Vector2f expected_position = position_before_move + velocity;
    game.move_player();
    sf::Vector2f position_after_move = game.get_player_best().get_balls()[0].get_position();
    EXPECT_EQ(position_after_move, expected_position);
}

TEST(GameTest, checkCollision) {
    Game game;
    game.get_player_best().add_ball(sf::Vector2f(100, 100), 10.f);
    sf::Vector2f static_ball_position = sf::Vector2f(100, 100);
    int netX = static_ball_position.x / game.get_net_size();
    int netY = static_ball_position.y / game.get_net_size();
    Ball ball(static_ball_position, 10.f, sf::Color::White);
    game.push_to_net(ball, netX, netY);
    game.set_count_balls(1);
    game.checkCollision();
    EXPECT_EQ(game.get_count_balls(), 0);
}

TEST(GameTest, checkJoin) {
    Game game;
    game.get_player_best().add_ball(sf::Vector2f(100,100), 10.f);
    game.get_player_best().add_ball(sf::Vector2f(100,100), 20.f);
    int size_before = game.get_player_best().get_balls().size();
    game.checkJoin();
    int size_after = game.get_player_best().get_balls().size();
    EXPECT_LT(size_after, size_before);
}

TEST(GameTest, splitBalls)
{
    Game game;

    int before_split = game.get_player_best().get_balls().size();
    game.splitBalls();
    int after_split = game.get_player_best().get_balls().size();
    GTEST_ASSERT_EQ(after_split, before_split + 1);
}

TEST(GameTest, spawnBalls)
{
    Game game;
    game.spawnBalls();
    int number_of_balls = game.get_count_balls();
    std::cout<<"number_of_balls: "<<number_of_balls<<std::endl;
    GTEST_ASSERT_EQ(number_of_balls, 1);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
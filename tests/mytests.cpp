#include <gtest/gtest.h>
#include "myfunctions.h"
#include "../include/Game.h"
// #include "../include/Ball.h"
// #include "../include/Board.h"

TEST(create_game, OnlyOnePlayer)
{
    Game game;
    GTEST_ASSERT_EQ(game.get_player_best().get_balls().size(), 1);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include <gtest/gtest.h>
#include "myfunctions.h"
#include "../include/Game.h"

TEST(myfunctions, add)
{
    GTEST_ASSERT_EQ(add(10, 22), 32);
}

TEST(abc, abcde)
{
    GTEST_ASSERT_EQ(1, 1);
}

TEST(create_game, game)
{
    Game game;
    

}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
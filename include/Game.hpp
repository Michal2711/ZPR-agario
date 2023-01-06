#pragma once

#include<iostream>
#include<ctime>
#include<vector>

#include "../include/Ball.hpp"
#include "../include/Player.hpp"
#include "../include/Board.hpp"


class Game
{
    private:
        Board board;
        sf::Event sfmlEvent;

        bool result;

        Player player;

        std::vector<Ball> small_balls;
        float max_spawn_time;
        float spawn_time;
        int max_small_balls;

        void initWindow();

    public:
        Game();
        ~Game();

        const bool running() const;
        void pollEvents();
        Player getPlayer() const;
        Board getBoard() const;

        void spawnBalls();
        void updatePlayer();
        void updateView();
        void updateCollision();
        void update();

        void render();
};
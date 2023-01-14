#include "Game.hpp"
#include <iostream>
#include <cmath>

void Game::initWindow()
{
    this->board.createBoard();
    // this->board.getWindow()->setFramerateLimit(60);
}

Game::Game()
{
    this->initWindow();
    this->result = false;
    this->max_spawn_time = 10.f;
    this->spawn_time = this->max_spawn_time;
    this->max_small_balls = 200;
    this->player.setDefault(this->board.getPlayerPosition());
    sf::Vector2f bot_pos = this->board.getPlayerPosition(); // change later for geting random postion of bots
    bot_pos.x = bot_pos.x;
    bot_pos.y = bot_pos.y - 10.f;

    this->bot.setDefault(bot_pos);
    this->bot.setColor(sf::Color::Red);
}

Game::~Game()
{
    delete this->board.getWindow();
}

const bool Game::running() const
{
    return this->board.getWindow()->isOpen();
}

Player Game::getPlayer() const
{
    return this->player;
}

Bot Game::getBot() const
{
    return this->bot;
}

Board Game::getBoard() const
{
    return this->board;
}

void Game::pollEvents()
{
    while (this->board.getWindow()->pollEvent(this->sfmlEvent))
    {
        if (this->sfmlEvent.type == sf::Event::Closed)
        {
            this->board.getWindow()->close();
        }
        else if (this->sfmlEvent.type == sf::Event::KeyPressed)
        {
            if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
                this->board.getWindow()->close();
        }
    }
}

void Game::spawnBalls()
{
    if (this->spawn_time < this->max_spawn_time)
        this->spawn_time += 1.f;
    else
    {
        if (this->small_balls.size() < this->max_small_balls)
        {
            this->small_balls.push_back(Ball(*this->board.getWindow()));
            this->spawn_time = 0.f;
        }
    }
}

void Game::updatePlayer()
{
    this->player.update(this->board.getWindow());
    sf::Vector2f pos = this->player.getShape().getPosition();
    std::cout << "Player pos:" << pos.x << " " << pos.y;
}

void Game::updateBot()
{
    this->bot.update(this->board.getWindow());
    sf::Vector2f pos = this->bot.getPosition();
    std::cout << "\tBot pos:" << pos.x << " " << pos.y << std::endl;
}

void Game::updateView()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->board.view.getCenter().x > 0)
    {
        this->board.setPlayerPositionX(-this->player.getSpeed());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->board.view.getCenter().x < 800)
    {
        this->board.setPlayerPositionX(this->player.getSpeed());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->board.view.getCenter().y > 0)
    {
        this->board.setPlayerPositionY(-this->player.getSpeed());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->board.view.getCenter().y < 600)
    {
        this->board.setPlayerPositionY(this->player.getSpeed());
    }
    // std::cout<<"X: "<<this->board.getPlayerPosition().x<<"Y: "<<this->board.getPlayerPosition().y<<std::endl;

    // this->board.getView().setCenter(this->board.getPlayerPosition());
    this->board.view.setCenter(this->board.getPlayerPosition());
    // }
    this->player.setPosition(this->board.getPlayerPosition());
    // std::cout<<"View x: "<<this->board.view.getCenter().x<<"\t";
    // std::cout<<"View y: "<<this->board.view.getCenter().y<<std::endl;
}

void Game::updateCollision()
{
    for (size_t i = 0; i < this->small_balls.size(); ++i)
    {
        if (this->player.getShape().getGlobalBounds().intersects(this->small_balls[i].getShape().getGlobalBounds()))
        {
            float new_size = this->player.getSize() + 0.1f;
            float new_speed = this->player.getSpeed() * 0.99;
            this->player.setSize(new_size);
            this->player.setSpeed(new_speed);
            this->small_balls.erase(this->small_balls.begin() + i);
        }
    }
    if (this->calculateDistance(this->player.getPosition(), this->bot.getPosition()) < this->player.getSize())
    {

        std::cout << "dupa" << std::endl;
    }
    else
    {
        std::cout << "nie dupa" << std::endl;
    }
}

float Game::calculateDistance(sf::Vector2f position_1, sf::Vector2f position_2)
{
    float dist_horizontal = std::pow((position_1.x - position_2.x), 2);
    float dist_vertical = std::pow((position_1.y - position_2.y), 2);
    return std::sqrt(dist_horizontal + dist_vertical);
}

void Game::update()
{
    this->pollEvents();

    if (this->result == false)
    {
        this->spawnBalls();
        this->updatePlayer();
        this->updateBot();
        this->updateView();
        this->updateCollision();
    }
}

void Game::render()
{
    this->board.getWindow()->clear(sf::Color(255, 255, 255));

    this->board.getWindow()->setView(this->board.getView());

    this->board.getWindow()->draw(this->board.getGrid());

    this->board.getWindow()->draw(this->board.getBoardSprite());

    this->player.render(*this->board.getWindow());

    // std::cin.ignore();

    this->bot.render(*this->board.getWindow());

    for (auto i : this->small_balls)
    {
        i.render(*this->board.getWindow());
    }
    this->board.getWindow()->display();
}
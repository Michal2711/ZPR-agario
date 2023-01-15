#include "Game.hpp"


void Game::initWindow(){
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

Board Game::getBoard() const
{
    return this->board;
}

void Game::pollEvents()
{
    while(this->board.getWindow()->pollEvent(this->sfmlEvent))
    {
        if (this->sfmlEvent.type == sf::Event::Closed){
            this->board.getWindow()->close();
        }
        else if (this->sfmlEvent.type == sf::Event::KeyPressed){
            if(this->sfmlEvent.key.code == sf::Keyboard::Escape)
                this->board.getWindow()->close();
        }
    }
}

void Game::spawnBalls()
{
    if (this->spawn_time < this->max_spawn_time)
        this -> spawn_time += 1.f;
    else
    {
        if ( this->small_balls.size() < this->max_small_balls)
        {
            this->small_balls.push_back(Ball(*this->board.getWindow()));
            this->spawn_time = 0.f;
        }
    }
}

void Game::updatePlayer()
{
    this->player.update(this->board.getWindow(), this->board.getWindow());
}

void Game::updateView()
{
    this->board.view.setCenter(this->player.getShape().getPosition());
}

void Game::updateCollision()
{
    for(size_t i = 0; i < this->small_balls.size(); ++i)
    {
        if(this->player.getShape().getGlobalBounds().intersects(this->small_balls[i].getShape().getGlobalBounds()))
        {
            float new_size = this->player.getSize() + 0.1f;
            float new_speed = this->player.getSpeed() * 0.99;
            this->player.setSize(new_size);
            this->player.setSpeed(new_speed);
            this->small_balls.erase(this->small_balls.begin() + i);
        }
    }
}

void Game::update()
{
    this->pollEvents();

    if(this->result == false)
    {
        this->spawnBalls();
		this->updatePlayer();
        // this->updateView();
		this->updateCollision();
    }
}

void Game::render()
{
    this->board.getWindow()->clear(sf::Color(255, 255, 255));

    this->board.getWindow()->setView(this->board.getView());

    this->board.getWindow()->draw(this->board.getGrid());

    // this->board.getWindow()->draw(this->board.getBoardSprite());

    this->player.render(*this->board.getWindow());

    for(auto i: this->small_balls)
    {
        i.render(*this->board.getWindow());
    }
    this->board.getWindow()->display();
}
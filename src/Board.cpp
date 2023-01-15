#include "../include/Board.hpp"
#include <iostream>


void Board::createBoard(){
    std::cout<<"createBoard"<<std::endl;
    // this->videoMode = sf::VideoMode()
    this->videoMode = sf::VideoMode(this->window_size_x, this->window_size_y);
    this->window = new sf::RenderWindow(this->videoMode, "Agario", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);

    // this->board_texture.create(this->board_texture_size, this->board_texture_size);

    // this->board_sprite.setTexture(this->board_texture);

    // this->view = sf::View(sf::Vector2f(this->window_size_x/2, this->window_size_y/2), sf::Vector2f(this->window_size_x/this->zoom, this->window_size_y/this->zoom));
    this->view = sf::View(sf::Vector2f(this->window_size_x, this->window_size_y), sf::Vector2f(this->window_size_x/this->zoom, this->window_size_y/this->zoom));

    this->player_position = sf::Vector2f(this->window_size_x/2, this->window_size_y/2);

    this->grid = sf::VertexArray(sf::Lines, 2*(numLines));
    this->window->setView(this->window->getDefaultView());
    sf::Vector2f size = this->window->getView().getSize();
    float rowH = size.y/this->rows;
    float colW = size.x/this->columns;

    this->setHorizontalCoordinates(rowH, size);
    this->setVerticalCoordinates(colW, size);
    this->setGridColor();
}

void Board::setPlayerPositionX(const float value) {
    this->player_position.x += value;
}

void Board::setPlayerPositionY(const float value) {
    this->player_position.y += value;
}

sf::VideoMode Board::getVideoMode() const {
    return this->videoMode;
}

sf::RenderWindow* Board::getWindow() const {
    return this->window;
}

sf::Vector2f Board::getWindowSize() const {
    return sf::Vector2f(this->window_size_x, this->window_size_y);
}

sf::View const& Board::getView() const {
    return this->view;
}

sf::Vector2f Board::getPlayerPosition() const {
    return this->player_position;
}

sf::Sprite Board::getBoardSprite() const {
    return this->board_sprite;
}

sf::VertexArray Board::getGrid() const {
    return this->grid;
}

void Board::setHorizontalCoordinates(float rowH, sf::Vector2f size){
    for(int i=0; i < this->rows-1; i++){
        int r = i+1;
        float rowY = rowH*r;
        this->grid[i*2].position = {0, rowY};
        this->grid[i*2+1].position = {size.x, rowY};
    }
}

void Board::setVerticalCoordinates(float colW, sf::Vector2f size){
    for(int i=rows-1; i < this->numLines; i++){
        int c = i-rows+2;
        float colX = colW*c;
        this->grid[i*2].position = {colX, 0};
        this->grid[i*2+1].position = {colX, size.y};
    }
}

void Board::setGridColor(){
    for(int i = 0; i< this->grid.getVertexCount(); ++i){
        this->grid[i].color = sf::Color(200, 200, 200);
    }
}

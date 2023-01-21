#include "../include/Board.h"
#include <algorithm>
#include <iostream>

void Board::createBoard()
{
    this->video_mode = sf::VideoMode(this->window_size_x, this->window_size_y);
    this->window = new sf::RenderWindow(this->video_mode, "Agario", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);

    this->view = sf::View(sf::Vector2f(this->window_size_x / 2, this->window_size_y / 2), sf::Vector2f(this->window_size_x / this->zoom, this->window_size_y / this->zoom));
    this->window->setView(this->view);
    this->player_pos = sf::Vector2f(this->window_size_x/2, this->window_size_y/2);

    this->grid = sf::RectangleShape(sf::Vector2f(this->bounds_size.x, this->bounds_size.y));
    grid.setPosition((this->window_size_x - grid.getSize().x) / 2, ( this->window_size_y - grid.getSize().y) / 2);
    grid.setFillColor(sf::Color::Black);
    this->grid_lines = sf::VertexArray(sf::Lines);
    this->create_grid_lines();
};

void Board::checkClosed()
{
    if (this->window->pollEvent(this->sfmlEvent))
    {
        if (this->sfmlEvent.type == sf::Event::Closed)
        {
            this->window->close();
        }
        else if (this->sfmlEvent.type == sf::Event::KeyPressed)
        {
            if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
                this->window->close();
        }
    }
};

const bool Board::is_running() const
{
    return this->window->isOpen();
};

void Board::render(Player player)
{
    this->checkClosed();
    this->window->clear(sf::Color::White);

    // TODO: this will be player

    this->draw_grid();
    this->draw_grid_lines();

    
    this->draw_player(player);


    // float view_x = std::min(this->player_pos.x, 800.f);
    // float view_y = std::min(this->player_pos.y, 600.f);


    this->view.setCenter(this->player_pos);
    this->window->setView(this->view);
    this->window->display();
};

void Board::draw_player(Player player)
{
    this->window->draw(player.get_shape());
};

void Board::draw_grid()
{
    this->window->draw(this->grid);
}

void Board::draw_grid_lines()
{
    this->window->draw(this->grid_lines);
}

void Board::create_grid_lines()
{
    for ( int i = 0; i < this->window_size_x; i+=this->cell_size){
        grid_lines.append(sf::Vertex(sf::Vector2f(i,0), sf::Color::White));
        grid_lines.append(sf::Vertex(sf::Vector2f(i, this->window_size_y), sf::Color::White));
    }
    for ( int i = 0; i < this->window_size_y; i+=this->cell_size){
        grid_lines.append(sf::Vertex(sf::Vector2f(0, i), sf::Color::White));
        grid_lines.append(sf::Vertex(sf::Vector2f(this->window_size_x, i), sf::Color::White));
    }
}

void Board::set_player_pos(sf::Vector2f new_pos)
{
    this->player_pos = new_pos;
}

sf::FloatRect Board::get_bounds()
{
    return this->bounds;
};

sf::RenderWindow* Board::getWindow() const
{
    return this->window;
}

sf::Vector2i Board::get_mouse_pos()
{
    sf::Vector2i position = sf::Mouse::getPosition(*this->window);
    return position;
};

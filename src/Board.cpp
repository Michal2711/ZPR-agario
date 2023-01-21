#include "../include/Board.h"

void Board::createBoard()
{
    this->video_mode = sf::VideoMode(this->window_size_x, this->window_size_y);
    this->window = new sf::RenderWindow(this->video_mode, "Agario", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);

    this->view = sf::View(sf::Vector2f(this->window_size_x / 2, this->window_size_y / 2), sf::Vector2f(this->window_size_x, this->window_size_y));
    this->window->setView(this->view);
    this->player_pos = sf::Vector2f(this->window_size_x / 2, this->window_size_y / 2);

    this->grid = sf::RectangleShape(sf::Vector2f(this->bounds_size.x, this->bounds_size.y));
    grid.setPosition((this->window_size_x - grid.getSize().x) / 2, (this->window_size_y - grid.getSize().y) / 2);
    grid.setFillColor(sf::Color::White);
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

    this->draw_grid();
    this->draw_grid_lines();
    this->draw_player(player);

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
    for (int i = this->cell_size + grid.getPosition().x; i < this->grid.getPosition().x + grid.getSize().x; i += this->cell_size)
    {
        grid_lines.append(sf::Vertex(sf::Vector2f(i, this->grid.getPosition().y), sf::Color::Black));
        grid_lines.append(sf::Vertex(sf::Vector2f(i, this->grid.getPosition().y + this->grid.getSize().y), sf::Color::Black));
    }
    for (int i = this->cell_size + grid.getPosition().y; i < grid.getPosition().y + this->grid.getSize().y; i += this->cell_size)
    {
        grid_lines.append(sf::Vertex(sf::Vector2f(this->grid.getPosition().x, i), sf::Color::Black));
        grid_lines.append(sf::Vertex(sf::Vector2f(this->grid.getPosition().x + this->grid.getSize().x, i), sf::Color::Black));
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

sf::Vector2f Board::get_mouse_pos()
{
    sf::Vector2f position = sf::Vector2f(sf::Mouse::getPosition(*this->window));
    return position;
};
sf::Vector2f Board::get_window_centre()
{
    return sf::Vector2f(this->window_size_x / 2, this->window_size_y / 2);
};

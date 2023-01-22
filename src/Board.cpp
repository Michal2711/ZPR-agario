#include "../include/Board.h"
#include <iostream>

void Board::createBoard()
{
    this->video_mode = sf::VideoMode(this->window_size_x, this->window_size_y);
    // this->video_mode = sf::VideoMode(20, 20);
    this->window = new sf::RenderWindow(this->video_mode, "Agario", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);

    this->view = sf::View(sf::Vector2f(this->window_size_x / 2, this->window_size_y / 2), sf::Vector2f(this->window_size_x, this->window_size_y));
    this->window->setView(this->view);
    this->player_pos = sf::Vector2f(this->window_size_x / 2, this->window_size_y / 2);

    // this->net(this->net_width, std::vector<std::vector<Ball*>>(this->net_height));
    // std::vector<std::vector<std::vector<Ball*>>> net(net_width, std::vector<std::vector<Ball*>>(net_height));

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

void Board::render(Ball player, Ball player2, std::unordered_map<int, std::unordered_map<int, std::vector<Ball>>> net)
{
    this->checkClosed();
    this->window->clear(sf::Color::White);

    // this->update_player_origin(player.get_position());



    this->draw_grid();
    this->draw_grid_lines();
    this->draw_player(player);
    this->draw_player(player2);

    for (auto& [firstKey, innerMap] : net) {
        for (auto& [secondKey, balls] : innerMap) {
            for (auto ball : balls) {
                this->draw_ball(ball);
                // std::cout<<"position: "<<"\t"<<typeid(*ball).name()<<std::endl;
            }
        }
    }

    sf::Vector2f view_center = player2.get_position() - player.get_position();
    view_center.x /= 2;
    view_center.y /= 2;
    view_center += player.get_position();
    // std::cout << "Center:" << view_center.x << ":" << view_center.y << std::endl;

    this->view.setCenter(view_center);
    // this->view.setCenter(sf::Vector2f(this->window_size_x / 2, this->window_size_y / 2));
    this->window->setView(this->view);
    this->window->display();
};

void Board::draw_player(Ball player)
{
    this->window->draw(player.get_shape());
};

void Board::draw_ball(Ball ball)
{
    // std::cout<<"get_shape(): "<<ball.get_shape()<<std::endl;
    this->window->draw(ball.get_shape());
}

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

// delete this
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

sf::Vector2f Board::get_view_centre()
{
    return this->view.getCenter();
}

sf::RenderWindow* Board::get_window() const
{
    return this->window;
}

sf::Vector2u Board::get_bound() const
{
    return sf::Vector2u(this->bound, this->bound);
}

void Board::update_player_origin(sf::Vector2f player_move){
    // this->player_origin -= getplayer_move;
    // this->player_origin.y = player_move.y;
    // std::cout
    // << "Window: " << this->player_origin.x << ":" << this->player_origin.y << std::endl;
};
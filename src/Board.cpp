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

    this->spawn_static_balls();
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

void Board::render(Ball player, Ball player2)
{
    this->checkClosed();
    this->window->clear(sf::Color::White);

    // this->update_player_origin(player.get_position());



    this->draw_grid();
    this->draw_grid_lines();
    this->draw_player(player);
    this->draw_player(player2);

    // for(auto i: this->)

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

void Board::draw_static_balls()
{

}

void Board::draw_player(Ball player)
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

// delete this
void Board::set_player_pos(sf::Vector2f new_pos)
{
    this->player_pos = new_pos;
}

void Board::set_count_balls(int new_count)
{
    this->count_balls = new_count;
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

void Board::spawn_static_balls()
{
    sf::Color color;
    sf::Vector2f position;
    for ( int i = 0; i < this->max_balls; ++i){
        color = sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
        position = sf::Vector2f(
            static_cast<float>(rand() % this->window_size_x),
            static_cast<float>(rand() % this->window_size_y)
        );
        // Ball* ball = new Ball(position, color);
        this->net[position.x/this->net_size][position.y/this->net_size].push_back(&Ball(position, color));
        this->count_balls += 1;
        this->draw_ball_from_net(position.x/this->net_size, position.y/this->net_size, this->count_balls);
        // this->net[position.x/this->net_size][position.y/this->net_size]->get_shape();
        // this->window->draw(ball->get_shape())

    }
}

void Board::draw_ball_from_net(const float x, const float y, int count) const
{
    this->window->draw(net[x][y][count]->get_shape());
}

void Board::removeBall(Ball* ball)
{
    float netX = ball->get_position().x;
    float netY = ball->get_position().y;
    auto& cell = net[netX][netY];
    auto it = std::find(cell.begin(), cell.end(), ball);
    if ( it != cell.end()){
        cell.erase(it);
    }
}

int Board::get_max_balls() const
{
    return this->max_balls;
}

void Board::update_player_origin(sf::Vector2f player_move){
    // this->player_origin -= getplayer_move;
    // this->player_origin.y = player_move.y;
    // std::cout
    // << "Window: " << this->player_origin.x << ":" << this->player_origin.y << std::endl;
};
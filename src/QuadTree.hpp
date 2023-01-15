#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include <cmath>

const int CELL_SIZE = 64;

class QuadTree
{
public:
    QuadTree(int level, sf::FloatRect bounds) :
        m_level(level), m_bounds(bounds)
    {
        if (level >= MAX_LEVELS)
            return;

        m_nodes[0] = new QuadTree(level + 1, { bounds.left, bounds.top, bounds.width / 2, bounds.height / 2 });
        m_nodes[1] = new QuadTree(level + 1, { bounds.left + bounds.width / 2, bounds.top, bounds.width / 2, bounds.height / 2 });
        m_nodes[2] = new QuadTree(level + 1, { bounds.left, bounds.top + bounds.height / 2, bounds.width / 2, bounds.height / 2 });
        m_nodes[3] = new QuadTree(level + 1, { bounds.left + bounds.width / 2, bounds.top + bounds.height / 2, bounds.width / 2, bounds.height / 2 });
    }

    ~QuadTree()
    {
        for (int i = 0; i < 4; i++)
        {
            if (m_nodes[i] != nullptr)
                delete m_nodes[i];
        }
    }

    void insert(sf::CircleShape* shape)
    {
        if (m_level >= MAX_LEVELS)
        {
            m_objects.push_back(shape);
            return;
        }

        int index = getIndex(shape->getPosition());
        if (index != -1)
        {
            m_nodes[index]->insert(shape);
            return;
        }

        m_objects.push_back(shape);
    }

    std::list<sf::CircleShape*> retrieve(std::list<sf::CircleShape*> returnObjects, sf::Vector2f pos)
    {
        int index = getIndex(pos);
        if (index != -1 && m_nodes[0] != nullptr)
        {
            m_nodes[index]->retrieve(returnObjects, pos);
        }

        for (auto& obj : m_objects)
        {
            returnObjects.push_back(obj);
        }
        return returnObjects;
    }

private:
    int getIndex(sf::Vector2f pos)
    {
        int index = -1;
        double verticalMidpoint = m_bounds.left + (m_bounds.width / 2);
        double horizontalMidpoint = m_bounds.top + (m_bounds.height / 2);
            // Object can completely fit within the top quadrant
        bool topQuadrant = (pos.y < horizontalMidpoint && pos.y > m_bounds.top);
            // Object can completely fit within the bottom quadrant
        bool bottomQuadrant = (pos.y > horizontalMidpoint && pos.y < m_bounds.top + m_bounds.height);

        // Object can completely fit within the left quadrants
        if (pos.x < verticalMidpoint && pos.x > m_bounds.left)
        {
            if (topQuadrant)
            {
                index = 1;
            }
            else if (bottomQuadrant)
            {
                index = 2;
            }
        }
        // Object can completely fit within the right quadrants
        else if (pos.x > verticalMidpoint && pos.x < m_bounds.left + m_bounds.width)
        {
            if (topQuadrant)
            {
                index = 0;
            }
            else if (bottomQuadrant)
            {
                index = 3;
            }
        }
        return index;
    }
    int m_level;
    std::list<sf::CircleShape*> m_objects;
    QuadTree* m_nodes[4];
    sf::FloatRect m_bounds;
    static const int MAX_LEVELS = 5;
};

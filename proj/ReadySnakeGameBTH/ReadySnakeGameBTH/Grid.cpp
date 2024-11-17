#include "Grid.h"
#include "Constants.h"
#include <cstdlib>

namespace Game {

    Grid::Grid()
        : m_apple(nullptr)
    {
        configure(DEFAULT_GRID_SIZE, DEFAULT_GRID_SPACING);

        m_horizontalLine.setFillColor(DEFAULT_GRID_COLOR);
        m_verticalLine.setFillColor(DEFAULT_GRID_COLOR);
    }

    void Grid::configure(float size, float spacing)
    {
        setSize(size);
        m_spacing = spacing;
        m_lineCount = static_cast<int>(getSize() / m_spacing);

        m_horizontalLine.setSize(sf::Vector2f(getSize(), 1.0f));
        m_verticalLine.setSize(sf::Vector2f(1.0f, getSize()));
    }

    void Grid::draw(Game::Window& window)
    {
        sf::Vector2f position;
        for (int i = 0; i <= m_lineCount; i++)
        {
            position.x = 0.0f;
            position.y = i * m_spacing;
            m_horizontalLine.setPosition(position);

            position.x = i * m_spacing;
            position.y = 0.0f;
            m_verticalLine.setPosition(position);

            window.draw(m_horizontalLine);
            window.draw(m_verticalLine);
        }

        if (m_apple) {
            m_apple->draw(window);
        }
    }

    void Grid::setApple(Apple* apple) {
        m_apple = apple;
    }

    Apple* Grid::getApple() const {
        return m_apple;
    }

    void Grid::update() {
    }

    void Grid::move() {
    }

}
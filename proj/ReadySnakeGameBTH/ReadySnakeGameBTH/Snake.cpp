#include "Snake.h"
#include "Window.h"
#include <iostream>
#include <cstdlib>

namespace Game {

    Snake::Snake()
        : m_isReady(false), m_isGameOver(false), m_distanceCovered(0.0f), m_segmentSize(30.0f), m_windowWidth(0.0f), m_windowHeight(0.0f)
    {
        m_newDirection = Direction::Right;
    }

    Snake::~Snake()
    {
        for (auto segment : m_segments)
        {
            delete segment;
        }
        m_segments.clear();
    }

    void Snake::setup(float segmentSize, float windowWidth, float windowHeight)
    {
        if (segmentSize <= 0 || windowWidth <= 0 || windowHeight <= 0) {
            std::cerr << "Error: Invalid setup parameters" << std::endl;
            return;
        }

        m_isReady = true;
        m_segmentSize = segmentSize;
        m_windowWidth = windowWidth;
        m_windowHeight = windowHeight;
        addSegment();
        addSegment();
        addSegment();
        addSegment();
    }

    void Snake::addSegment()
    {
        if (!m_segments.empty())
        {
            m_segments.push_back(m_segments.back()->generateNewSegment());
        }
        else
        {
            m_segments.push_back(new SnakeSegment());
        }
    }

    void Snake::move()
    {
        if (!m_isReady || m_isGameOver) return;

        for (auto& segment : m_segments)
        {
            segment->move();
        }
        m_distanceCovered += m_segments[0]->getSpeed();

        if (m_distanceCovered >= m_segments[0]->getSize())
        {
            if (checkIfWallCollision() || checkIfSelfCollision())
            {
                m_isGameOver = true;
                return;
            }

            for (size_t i = m_segments.size() - 1; i > 0; --i)
            {
                m_segments[i]->setDirection(m_segments[i - 1]->getDirection());
            }
            m_segments[0]->setDirection(m_newDirection);
            m_distanceCovered = 0.0f;
        }
    }

    void Snake::setDirection(Direction newDirection) {
        m_newDirection = newDirection;
    }

    void Snake::checkIfFoodEaten(Grid& grid)
    {
        Apple* food = grid.getApple();
        if (food && m_segments[0]->getPosition() == food->getPosition())
        {
            scoreManager.increaseScore();
            addSegment();

            int columns = static_cast<int>(m_windowWidth / m_segmentSize);
            int rows = static_cast<int>(m_windowHeight / m_segmentSize);
            float x = (std::rand() % columns) * m_segmentSize;
            float y = (std::rand() % rows) * m_segmentSize;
            food->setPosition(sf::Vector2f(x, y));
        }
    }

    bool Snake::checkIfSelfCollision() const
    {
        for (size_t i = 1; i < m_segments.size(); ++i)
        {
            if (m_segments[0]->getPosition() == m_segments[i]->getPosition())
            {
                return true;
            }
        }
        return false;
    }

    bool Snake::checkIfWallCollision() const
    {
        auto position = m_segments[0]->getPosition();
        if (position.x < 0 || position.x >= m_windowWidth ||
            position.y < 0 || position.y >= m_windowHeight)
        {
            return true;
        }
        return false;
    }

    void Snake::draw(Window& window)
    {
        if (!m_isReady) return;

        for (auto& segment : m_segments)
        {
            segment->draw(window);
        }
    }

    void Snake::update() {

    }

}
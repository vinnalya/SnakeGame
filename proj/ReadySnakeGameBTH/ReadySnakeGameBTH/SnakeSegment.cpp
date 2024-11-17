#include "SnakeSegment.h"
#include "Constants.h"

namespace Game {
    SnakeSegment::SnakeSegment()
        : m_direction(Direction::Right),
        m_size(SNAKE_SEGMENT_SIZE),
        m_speed(SNAKE_SPEED) {
        m_shape.setFillColor(SNAKE_COLOR);
        m_shape.setOutlineColor(SNAKE_OUTLINE_COLOR);
        m_shape.setOutlineThickness(SNAKE_OUTLINE_THICKNESS);
        m_shape.setSize(sf::Vector2f(m_size, m_size));
        m_position = sf::Vector2f(0.0f, 0.0f);
    }

    SnakeSegment* SnakeSegment::generateNewSegment() {
        sf::Vector2f newPosition = m_position;

        switch (m_direction) {
        case Direction::Right:
            newPosition.x -= m_size;
            break;
        case Direction::Left:
            newPosition.x += m_size;
            break;
        case Direction::Up:
            newPosition.y += m_size;
            break;
        case Direction::Down:
            newPosition.y -= m_size;
            break;
        }

        SnakeSegment* newSegment = new SnakeSegment();
        newSegment->setPosition(newPosition);
        newSegment->setDirection(m_direction);
        return newSegment;
    }

    void SnakeSegment::setDirection(Direction direction) {
        m_direction = direction;
    }

    Direction SnakeSegment::getDirection() const {
        return m_direction;
    }

    void SnakeSegment::setSize(float size) {
        m_size = size;
        m_shape.setSize(sf::Vector2f(m_size, m_size));
    }

    float SnakeSegment::getSize() const {
        return m_size;
    }

    void SnakeSegment::setSpeed(float speed) {
        m_speed = speed;
    }

    float SnakeSegment::getSpeed() const {
        return m_speed;
    }

    void SnakeSegment::setColor(sf::Color color) {
        m_shape.setFillColor(color);
    }

    void SnakeSegment::move() {
        switch (m_direction) {
        case Direction::Right:
            m_position.x += m_speed;
            break;
        case Direction::Left:
            m_position.x -= m_speed;
            break;
        case Direction::Up:
            m_position.y -= m_speed;
            break;
        case Direction::Down:
            m_position.y += m_speed;
            break;
        }
    }

    void SnakeSegment::draw(Window& window) {
        m_shape.setPosition(m_position);
        window.getRenderWindow().draw(m_shape);
    }

    void SnakeSegment::update() {
    }
}
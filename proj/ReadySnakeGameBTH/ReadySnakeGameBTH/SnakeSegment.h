#pragma once
#include "GameObject.h"
#include "Constants.h"
#include <SFML/Graphics.hpp>

namespace Game {
    class SnakeSegment : public GameObject {
    public:
        SnakeSegment();

        SnakeSegment* generateNewSegment();
        void setDirection(Direction direction);
        Direction getDirection() const;
        float getSize() const;
        void setSize(float size);

        void setSpeed(float speed);
        float getSpeed() const;
        void setColor(sf::Color color);
        void move() override;
        void draw(Window& window) override;
        void update() override;

    private:
        Direction m_direction;
        sf::RectangleShape m_shape;
        float m_size;
        float m_speed;
    };
}
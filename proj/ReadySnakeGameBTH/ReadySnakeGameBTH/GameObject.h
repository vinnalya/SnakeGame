#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"

namespace Game {

    class Window; 

    class GameObject
    {
    public:

        virtual void draw(Window& window) = 0;
        virtual void update() = 0;
        virtual void move() = 0;


        virtual ~GameObject() = default;


        void setPosition(const sf::Vector2f& position);
        sf::Vector2f getPosition() const;

        void setSize(float size);
        float getSize() const;

        void setColor(sf::Color color);
        sf::Color getColor() const;

    protected:

        sf::Vector2f m_position;
        float m_size;
        sf::Color m_color;
    };

}
#include "GameObject.h"

namespace Game {

    void GameObject::setPosition(const sf::Vector2f& position)
    {
        m_position = position;
    }

    sf::Vector2f GameObject::getPosition() const
    {
        return m_position;
    }

    void GameObject::setSize(float size)
    {
        m_size = size;
    }

    float GameObject::getSize() const
    {
        return m_size;
    }

    void GameObject::setColor(sf::Color color)
    {
        m_color = color;
    }

    sf::Color GameObject::getColor() const
    {
        return m_color;
    }

}
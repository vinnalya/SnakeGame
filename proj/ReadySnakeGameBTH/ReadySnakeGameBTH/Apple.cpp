#include "Apple.h"

namespace Game {

    Apple::Apple() {
        setSize(30.0f);
        setColor(sf::Color::Green);
        m_shape.setSize(sf::Vector2f(getSize(), getSize()));
        m_shape.setFillColor(getColor());
    }

    void Apple::draw(Window& window) {
        m_shape.setPosition(m_position);
        window.getRenderWindow().draw(m_shape);
    }

    void Apple::update() {

    }

}
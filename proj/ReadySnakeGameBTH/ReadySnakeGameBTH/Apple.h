#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

namespace Game {

    class Apple : public GameObject {
    public:
        Apple();
        void draw(Window& window) override;
        void update() override;
        void move() override {}

    private:
        sf::RectangleShape m_shape;
    };

}
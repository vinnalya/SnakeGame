#pragma once
#include "GameObject.h"
#include "Apple.h" 
#include <SFML/Graphics.hpp>

namespace Game {

    class Grid : public GameObject {
    public:
        Grid();

        void configure(float size, float spacing);

        void draw(Game::Window& window) override;
        void update() override;
        void move() override;

        void setApple(Apple* apple);
        Apple* getApple() const;

    private:
        sf::RectangleShape m_horizontalLine;
        sf::RectangleShape m_verticalLine;
        float m_spacing;
        int m_lineCount;
        Apple* m_apple;
    };

}

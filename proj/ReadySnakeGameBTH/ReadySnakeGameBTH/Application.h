#pragma once
#include "Window.h"
#include "Snake.h"
#include "Grid.h"
#include "Apple.h"
#include "ScoreManager.h"

namespace Game {

    class Application
    {
    public:
        Application();
        void setup(int width, int height);
        void start(int fps = 60);

    private:
        void createFrame();
        void render();
        void updateScene();
        void keyPressed(sf::Keyboard::Key key);
        void keyReleased(sf::Keyboard::Key key);
        void mouseMoved(sf::Event::MouseMoveEvent event);
        void mouseClicked(sf::Event::MouseButtonEvent event);

        Snake m_snake;
        Grid m_grid;
        Apple m_apple;
        Window m_window;
        sf::Clock m_clock;
        sf::Time m_frameDuration;
        sf::Time m_elapsedTime;
        ScoreManager m_scoreManager;
    };

}

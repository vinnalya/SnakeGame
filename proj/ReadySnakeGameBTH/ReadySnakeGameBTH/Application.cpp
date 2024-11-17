#include "Application.h"
#include <iostream>
#include "Constants.h"

namespace Game {

    Application::Application()
    {
        m_grid.configure(600, 30);
        m_grid.setApple(&m_apple);
        std::srand(time(0));

        int columns = static_cast<int>(DEFAULT_GRID_SIZE / DEFAULT_GRID_SPACING);
        int rows = static_cast<int>(DEFAULT_GRID_SIZE / DEFAULT_GRID_SPACING);
        float x = (std::rand() % columns) * DEFAULT_GRID_SPACING;
        float y = (std::rand() % rows) * DEFAULT_GRID_SPACING;
        m_apple.setPosition(sf::Vector2f(x, y));
    }

    void Application::setup(int width, int height)
    {
        m_window.create(width, height);
        m_snake.setup(30.0f, static_cast<float>(width), static_cast<float>(height));
        m_window.addMouseMoveFunction(
            std::bind(&Application::mouseMoved, this, std::placeholders::_1)
        );
        m_window.addMouseClickFunction(
            std::bind(&Application::mouseClicked, this, std::placeholders::_1)
        );
        m_window.addKeyPressFunction(
            std::bind(&Application::keyPressed, this, std::placeholders::_1)
        );
        m_window.addKeyReleaseFunction(
            std::bind(&Application::keyReleased, this, std::placeholders::_1)
        );
        m_scoreManager.resetScore();
    }

    void Application::start(int fps)
    {
        float frameDurationInSeconds = 1.0f / fps;
        m_frameDuration = sf::seconds(frameDurationInSeconds);

        m_elapsedTime = m_clock.restart();

        while (m_window.isOpen())
        {
            m_window.processEvents();

            m_elapsedTime = m_clock.getElapsedTime();

            if (m_elapsedTime >= m_frameDuration)
            {
                createFrame();
                m_elapsedTime = sf::seconds(0.0f);
                m_clock.restart();
            }
            else
            {
                sf::sleep(m_frameDuration - m_elapsedTime);
            }

            if (m_snake.isGameOver())
            {
                std::cout << "Game Over!" << std::endl;
                break;
            }
        }
    }

    void Application::createFrame()
    {
        updateScene();
        render();
    }

    void Application::render()
    {
        m_window.clear();
        m_grid.draw(m_window);
        m_snake.draw(m_window);
        m_window.display();
    }

    void Application::updateScene()
    {
        m_snake.checkIfFoodEaten(m_grid);
        m_snake.move();
        m_grid.update();
    }

    void Application::keyPressed(sf::Keyboard::Key key)
    {
        if (key == sf::Keyboard::Left)
            m_snake.setDirection(Direction::Left);
        if (key == sf::Keyboard::Right)
            m_snake.setDirection(Direction::Right);
        if (key == sf::Keyboard::Up)
            m_snake.setDirection(Direction::Up);
        if (key == sf::Keyboard::Down)
            m_snake.setDirection(Direction::Down);
        if (key == sf::Keyboard::Space)
            m_snake.addSegment();
    }

    void Application::keyReleased(sf::Keyboard::Key key)
    {
    }

    void Application::mouseMoved(sf::Event::MouseMoveEvent event)
    {
    }

    void Application::mouseClicked(sf::Event::MouseButtonEvent event)
    {
    }

}
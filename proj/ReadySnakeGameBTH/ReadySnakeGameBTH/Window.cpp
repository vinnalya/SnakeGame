#include "Window.h"

namespace Game {

    void Window::create(unsigned int width, unsigned int height, const sf::String& title)
    {
        m_window.create(sf::VideoMode(width, height), title);
    }

    void Window::draw(sf::Drawable& shape)
    {
        m_window.draw(shape);
    }

    void Window::processEvents()
    {
        sf::Event event;

        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                for (auto function : m_keyPressFunctions)
                    function(event.key.code);
            }
            if (event.type == sf::Event::KeyReleased)
            {
                for (auto function : m_keyReleaseFunctions)
                    function(event.key.code);
            }
            if (event.type == sf::Event::MouseMoved)
            {
                for (auto function : m_mouseMoveFunctions)
                    function(event.mouseMove);
            }
        }
    }

    bool Window::isOpen() const
    {
        return m_window.isOpen();
    }

    void Window::clear()
    {
        m_window.clear(sf::Color::White);
    }

    void Window::display()
    {
        m_window.display();
    }

    void Window::addKeyPressFunction(KeyboardFunction newFunction)
    {
        m_keyPressFunctions.push_back(newFunction);
    }

    void Window::addKeyReleaseFunction(KeyboardFunction newFunction)
    {
        m_keyReleaseFunctions.push_back(newFunction);
    }

    void Window::addMouseMoveFunction(MouseMoveFunction newFunction)
    {
        m_mouseMoveFunctions.push_back(newFunction);
    }

    void Window::addMouseClickFunction(MouseClickFunction newFunction)
    {
        m_mouseClickFunctions.push_back(newFunction);
    }

}
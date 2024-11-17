#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>
#include <SFML/Window/Event.hpp>

namespace Game {

    class Window
    {
    public:
        using KeyboardFunction = std::function<void(sf::Keyboard::Key)>;
        using KeyboardFunctionList = std::vector<KeyboardFunction>;

        using MouseMoveFunction = std::function<void(sf::Event::MouseMoveEvent)>;
        using MouseMoveFunctionList = std::vector<MouseMoveFunction>;

        using MouseClickFunction = std::function<void(sf::Event::MouseButtonEvent)>;
        using MouseClickFunctionList = std::vector<MouseClickFunction>;

        void create(unsigned int width, unsigned int height, const sf::String& title = "Square Snake");
        void draw(sf::Drawable& shape);
        void processEvents();

        bool isOpen() const;

        void clear();
        void display();
        void addKeyPressFunction(KeyboardFunction newFunction);
        void addKeyReleaseFunction(KeyboardFunction newFunction);
        void addMouseMoveFunction(MouseMoveFunction newFunction);
        void addMouseClickFunction(MouseClickFunction newFunction);

        sf::RenderWindow& getRenderWindow() {
            return m_window;
        }

    private:
        KeyboardFunctionList m_keyPressFunctions;
        KeyboardFunctionList m_keyReleaseFunctions;
        MouseMoveFunctionList m_mouseMoveFunctions;
        MouseClickFunctionList m_mouseClickFunctions;
        sf::RenderWindow m_window;
    };

}
#include "ScoreManager.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include "Application.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Snake Game");
    Menu menu(window);
    ScoreManager scoreManager;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    menu.MoveUp();
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    menu.MoveDown();
                }
                if (event.key.code == sf::Keyboard::Return)
                {
                    int selection = menu.MenuPressed();
                    if (selection == 0)
                    {
                        Game::Application app;
                        app.setup(window.getSize().x, window.getSize().y);
                        app.start(60);
                    }
                    else if (selection == 1)
                    {
                        menu.processSelection(1);
                    }
                    else if (selection == 2)
                    {
                        scoreManager.showHighScore(window, menu.getFont());
                    }
                    else if (selection == 3)
                    {
                        window.close();
                    }
                }

                if (event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::BackSlash)
                {
                    menu.exitControlsMode();
                }
            }
        }

        window.clear();
        menu.draw(window);
        window.display();
    }

    return 0;
}

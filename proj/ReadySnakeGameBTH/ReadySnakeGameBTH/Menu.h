#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

class Menu
{
public:
    Menu(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    void MoveUp();
    void MoveDown();
    int MenuPressed() const { return MenuSelected; }
    const sf::Font& getFont() const { return font; }

    void processSelection(int selection);
    void exitControlsMode();

    ~Menu();

private:
    int MenuSelected;
    sf::Font font;
    sf::Text mainMenu[4];
    sf::RenderWindow& window;

    enum class MenuState { ShowingMenu, ShowingControls };
    MenuState currentState;

    sf::Text controlsDisplay;
};
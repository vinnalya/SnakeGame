#include "Menu.h"

Menu::Menu(sf::RenderWindow& win) : window(win), currentState(MenuState::ShowingMenu)
{
    if (!font.loadFromFile("Workbench-Regular.ttf")) {
        std::cout << "No font is here" << std::endl;
    }

    float width = window.getSize().x;
    float height = window.getSize().y;
    float menuItemHeight = height / 5.0f;

    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(sf::Color::White);
    mainMenu[0].setString("Play");
    mainMenu[0].setCharacterSize(40);
    mainMenu[0].setPosition(sf::Vector2f(width / 2 - 50, menuItemHeight * 1));

    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(sf::Color::White);
    mainMenu[1].setString("Controls");
    mainMenu[1].setCharacterSize(40);
    mainMenu[1].setPosition(sf::Vector2f(width / 2 - 50, menuItemHeight * 2));

    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(sf::Color::White);
    mainMenu[2].setString("High Score");
    mainMenu[2].setCharacterSize(40);
    mainMenu[2].setPosition(sf::Vector2f(width / 2 - 50, menuItemHeight * 3));

    mainMenu[3].setFont(font);
    mainMenu[3].setFillColor(sf::Color::White);
    mainMenu[3].setString("Exit");
    mainMenu[3].setCharacterSize(40);
    mainMenu[3].setPosition(sf::Vector2f(width / 2 - 50, menuItemHeight * 4));

    MenuSelected = 0;
}

Menu::~Menu() {}

void Menu::draw(sf::RenderWindow& window)
{
    if (currentState == MenuState::ShowingMenu) {
        for (int i = 0; i < 4; i++) { 
            window.draw(mainMenu[i]);
        }
    }
    else if (currentState == MenuState::ShowingControls) {
        window.draw(controlsDisplay);
    }
}

void Menu::MoveUp()
{
    if (currentState == MenuState::ShowingMenu) {
        if (MenuSelected - 1 >= 0) {
            mainMenu[MenuSelected].setFillColor(sf::Color::White);
            MenuSelected--;
            mainMenu[MenuSelected].setFillColor(sf::Color::Yellow);
        }
    }
}

void Menu::MoveDown()
{
    if (currentState == MenuState::ShowingMenu) {
        if (MenuSelected + 1 < 4) {
            mainMenu[MenuSelected].setFillColor(sf::Color::White);
            MenuSelected++;
            mainMenu[MenuSelected].setFillColor(sf::Color::Yellow);
        }
    }
}

void Menu::processSelection(int selection)
{
    if (selection == 1) {  // Controls seçeneği
        std::ifstream controlsFile("controls.txt");
        if (!controlsFile.is_open()) {
            std::cout << "Failed to load 'controls.txt'. Reason: Unable to open file" << std::endl;
            return;
        }

        std::string line;
        std::string controlsText;
        while (std::getline(controlsFile, line)) {
            controlsText += line + "\n";
        }

        controlsFile.close();

        controlsDisplay.setFont(font);
        controlsDisplay.setCharacterSize(20);
        controlsDisplay.setFillColor(sf::Color::White);
        controlsDisplay.setPosition(sf::Vector2f(50, 50));
        controlsDisplay.setString(controlsText);

        currentState = MenuState::ShowingControls;
    }
}

void Menu::exitControlsMode()
{
    currentState = MenuState::ShowingMenu;
}
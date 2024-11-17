#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>

class ScoreManager
{
public:
    ScoreManager();
    ~ScoreManager();

    void increaseScore();
    int getScore() const;
    int getHighScore() const;
    void resetScore();
    void saveHighScore();
    void loadHighScore();

    void showHighScore(sf::RenderWindow& window, const sf::Font& font) const;

private:
    int score;
    int highScore;
    const std::string scoreFile = "scores.txt";
};

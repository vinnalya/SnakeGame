#include "ScoreManager.h"

ScoreManager::ScoreManager() : score(0), highScore(0)
{
    loadHighScore();
}

ScoreManager::~ScoreManager()
{
    saveHighScore();
}

void ScoreManager::increaseScore()
{
    score++;
}

int ScoreManager::getScore() const
{
    return score;
}

int ScoreManager::getHighScore() const
{
    return highScore;
}

void ScoreManager::resetScore()
{
    score = 0;
}

void ScoreManager::saveHighScore()
{
    if (score > highScore) {
        highScore = score;
        std::ofstream file(scoreFile);
        if (file.is_open()) {
            file << highScore;
            file.close();
        }
    }
}

void ScoreManager::loadHighScore()
{
    std::ifstream file(scoreFile);
    if (file.is_open()) {
        file >> highScore;
        file.close();
    }
}

void ScoreManager::showHighScore(sf::RenderWindow& window, const sf::Font& font) const
{
    sf::Text highScoreText;
    highScoreText.setFont(font);
    highScoreText.setCharacterSize(36);
    highScoreText.setFillColor(sf::Color::White);
    highScoreText.setPosition(100.0f, 150.0f);

    highScoreText.setString("High Score: " + std::to_string(getHighScore()));

    while (window.isOpen())
    {
        window.clear();
        window.draw(highScoreText);
        window.display();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::Closed)
            {
                return;
            }
        }
    }
}

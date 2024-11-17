#pragma once
#include <SFML/Graphics.hpp>

constexpr unsigned int WINDOW_WIDTH = 600;
constexpr unsigned int WINDOW_HEIGHT = 600;

constexpr float DEFAULT_GRID_SIZE = 600.0f;
constexpr float DEFAULT_GRID_SPACING = 30.0f;
const sf::Color DEFAULT_GRID_COLOR = sf::Color::Green;

constexpr float SNAKE_SEGMENT_SIZE = 30.0f;
constexpr float SNAKE_SPEED = 5.0f;
const sf::Color SNAKE_COLOR = sf::Color::Red;
const sf::Color SNAKE_OUTLINE_COLOR = sf::Color::Blue;
constexpr float SNAKE_OUTLINE_THICKNESS = 2.0f;

constexpr int FPS = 60;
const sf::Color BACKGROUND_COLOR = sf::Color::White;

enum class Direction
{
    Left,
    Right,
    Up,
    Down
};
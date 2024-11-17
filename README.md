# SnakeGame
 Object-Oriented Snake Game with C++ and SFML

## Overview
This project is a classic Snake game implemented in C++ using Object-Oriented Programming (OOP) principles and the SFML (Simple and Fast Multimedia Library). The game focuses on creating a modular, extensible, and efficient design using various OOP features like inheritance, encapsulation, dynamic memory management, and polymorphism.

The primary objective of the game is for the snake to collect food (apples) and grow longer while avoiding collisions with itself or the walls. The player can control the snake using keyboard inputs.

## Features
## 1 Object-Oriented Programming (OOP):
- Modular design using classes for different components (e.g., Snake, Apple, Grid, Window).
- Reusable and extensible class structure with inheritance and encapsulation.

## 2 SFML Integration:
- Uses SFML for rendering graphics, handling user input, and managing the game window.

## 3 Dynamic Memory Management:
- Dynamically allocates memory for snake segments.
- Proper cleanup of resources using destructors to prevent memory leaks.

## 4 Menu System:
- A simple main menu that allows players to start the game, view controls, or exit.

## 5 Menu System:
- Tracks the player's current score and saves the high score in a text file.


## Class Structure
## GameObject (Abstract Base Class):

- Provides common attributes and methods for all game objects.
- Includes draw, update, and move as pure virtual methods to be overridden by derived classes.

## Snake:

- Manages the snake's behavior, including movement, growth, and collision detection.
- Stores snake segments in a std::vector.

## SnakeSegment:

- Represents an individual segment of the snake.
- Tracks its position, size, and direction.

## Apple:

- Represents the food the snake eats.
- Handles its position and appearance.

## Grid:

- Defines the game field as a grid.
- Ensures the snake and apple align with the grid cells.

## ScoreManager:

- Tracks and updates the player's current and high scores.
- Reads and writes the high score to a text file.

## Window:

- Manages the SFML render window and event handling.

## Application:

- Coordinates the overall game flow, including initializing objects, running the main game loop, and handling user inputs.

## Menu:

- Displays the main menu options such as "Play," "Controls," and "Exit."


## How to Build and Run
- C++ Compiler
- SFML Library installed on your system
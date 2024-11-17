#pragma once
#include "GameObject.h"
#include "SnakeSegment.h"
#include "ScoreManager.h"
#include "Constants.h"
#include "Grid.h"
#include <vector>

namespace Game {

    class Snake : public GameObject {
    public:
        Snake();
        ~Snake();

        void setup(float segmentSize, float windowWidth, float windowHeight);
        void addSegment();
        void move() override;
        void setDirection(Direction newDirection);
        void draw(Window& window) override;
        void update() override;
        void checkIfFoodEaten(Grid& grid);
        bool checkIfSelfCollision() const;
        bool checkIfWallCollision() const;
        bool isGameOver() const { return m_isGameOver; }
        int getScore() const { return scoreManager.getScore(); }
        int getHighScore() const { return scoreManager.getHighScore(); }

    private:
        bool m_isReady;
        bool m_isGameOver;
        std::vector<SnakeSegment*> m_segments;
        float m_distanceCovered;
        float m_segmentSize;
        float m_windowWidth;
        float m_windowHeight;
        Direction m_newDirection;
        ScoreManager scoreManager;
    };

}
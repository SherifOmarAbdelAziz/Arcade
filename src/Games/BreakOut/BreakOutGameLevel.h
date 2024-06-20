/*
 * BreakOutGameLevel.h
 *
 *  Created on: May 25, 2024
 *      Author: sherif
 */

#ifndef GAMES_BREAKOUT_BREAKOUTGAMELEVEL_H_
#define GAMES_BREAKOUT_BREAKOUTGAMELEVEL_H_

#include "Block.h"
#include <vector>
#include <stdint.h>

class Screen;
class AARectangle;
class Ball;

class BreakOutGameLevel
{
    public:
        // BreakOutGameLevel();
        void init(const AARectangle& boundary);
        void load(std::vector<Block> blocks);
        void update(uint32_t dt, Ball& ball);
        void draw(Screen &screen);
        static std::vector<BreakOutGameLevel> loadLevelsFromFile(const std::string& filePath);
        bool isLevelComplete() const;

    private:
        static const int BLOCK_WIDTH = 30;
        static const int BLOCK_HEIGHT = 15;    
        void createDefaultLevel(const AARectangle& boundary);
        std::vector<Block> mBlocks;
};

#endif
/*
 * BreakOutGameLevel.h
 *
 *  Created on: May 25, 2024
 *      Author: sherif
 */

#include "BreakOutGameLevel.h"
#include "Screen.h"
#include "Ball.h"
#include "App.h"
#include "FileCommandLoader.h"

// #define BLOCK_WIDTH 30
// #define BLOCK_HEIGHT 15
#define HEALTH_POINTS 1

void BreakOutGameLevel::init(const AARectangle& boundary)
{
    //createDefaultLevel(boundary);
}

void BreakOutGameLevel::load(std::vector<Block> blocks)
{
    mBlocks.clear();
    mBlocks = blocks;
}

void BreakOutGameLevel::update(uint32_t dt, Ball& ball)
{
    std::vector<Block> collidedBlocks;
    Block* blockToBounceOffOfPtr = nullptr;
    BoundaryEdge edgeToBounceOffof;
    float max_magnitude = -1;

    // loop on blocks to check collision
    // then get collision offset based on closeset block to be hit
    for(auto& block : mBlocks)
    {
        BoundaryEdge edge;
        if(!block.isDestroyed()
            && block.HasCollided(ball.GetBoundingRect(), edge))
        {
            // Vec2D pointtoBounceOffof = Vec2D::Zero();
            float magnitude = block.GetCollisionOffset(ball.GetBoundingRect()).mag();
            if(magnitude > max_magnitude)
            {
                // max_magnitude = magnitude;
                blockToBounceOffOfPtr = &block;
                edgeToBounceOffof = edge;
            }
            collidedBlocks.push_back(block);
        }
    }

    // Bounce ball off the collided block
    // reduce HP of collided block (through its pointer)
    if(blockToBounceOffOfPtr != nullptr)
    {
        blockToBounceOffOfPtr->Bounce(ball, edgeToBounceOffof);
        blockToBounceOffOfPtr->reduceHealthPoints();
    }   
    
    // check collided blocks to make flush
    for (const auto& block : collidedBlocks)
    {
        BoundaryEdge edge;
        if(block.HasCollided(ball.GetBoundingRect(), edge))
        {
            Vec2D pointOnEdge = Vec2D::Zero();
            ball.MakeFlushWithEdge(edgeToBounceOffof, pointOnEdge, true);
        }
    }    
}

void BreakOutGameLevel::draw(Screen &screen)
{
    for(auto& block : mBlocks)
    {
        if(!block.isDestroyed())
        {
            block.draw(screen);
        }
    }
}

void BreakOutGameLevel::createDefaultLevel(const AARectangle& boundary)
{   
    // define num of blocks (rows & columns)
    uint8_t noOfBlocksAcross = (boundary.GetWidth()-(2*BLOCK_WIDTH))/BLOCK_WIDTH;
    uint8_t noOfBlocksRows = 5;

    // define starting point in x dimension
    float startingPointinX = BLOCK_WIDTH;
    //(boundary.GetWidth()-(noOfBlocksAcross*(BLOCK_WIDTH+1)))/2;

    // loop over rows 
    for(uint8_t row = 0; row < noOfBlocksRows; row++)
    {
        // then define starting rectangle for this row
        AARectangle blockRect = AARectangle(Vec2D(startingPointinX, (row + 1) * BLOCK_HEIGHT), BLOCK_WIDTH, BLOCK_HEIGHT);

        // then loop over columns to initialize each block (rect, blockColor, fillColor)
        for(uint8_t column = 0; column < noOfBlocksAcross; column++)
        {
            Block block;
            block.init(blockRect, HEALTH_POINTS, Color::Black(),Color::Green());
            mBlocks.push_back(block);
            blockRect.MoveBy(Vec2D(BLOCK_WIDTH, 0));
        }
    }
}

struct LayoutBlock
{
    char symbol = '-'; 
    uint8_t hp = 0;
    Color color = Color::Black();
};

LayoutBlock findLayoutBlockForSymbol(const std::vector<LayoutBlock>& blocks, char symbol)
{
    LayoutBlock retBlock = LayoutBlock();
    for(const auto& block : blocks)
    {
        if(block.symbol == symbol)
        {
            retBlock = block;
        }
    }
    return retBlock;
}

std::vector<BreakOutGameLevel> BreakOutGameLevel::loadLevelsFromFile(const std::string& filePath)
{
    std::vector<BreakOutGameLevel> levels;

    std::vector<LayoutBlock> blocksLayouts; // each level has different layouts

    std::vector<Block> levelBlocks;

    FileCommandLoader fileLoader;

    uint32_t width = 0, height = 0;

    // defining level command
    Command levelCommand;
    levelCommand.command = "level";
    levelCommand.parseCommandFunc = [&](const FuncParams& Params)
    {
        if(levels.size() > 0)
        {
            levels.back().load(levelBlocks);
        }
        blocksLayouts.clear();
        levelBlocks.clear();
        width = 0; height = 0;

        BreakOutGameLevel level;
        level.init(AARectangle(Vec2D::Zero(), App::Singleton().Width(), App::Singleton().Height()));
        levels.push_back(level);
    };
    fileLoader.addCommand(levelCommand);

    // defining block command
    Command blockCommand;
    blockCommand.command = "block";
    blockCommand.parseCommandFunc = [&](const FuncParams& Params)
    {
        LayoutBlock blocksLayout;
        blocksLayouts.push_back(blocksLayout);
    };
    fileLoader.addCommand(blockCommand);  

    // defining symbol command  
    Command symbolCommand;
    symbolCommand.command = "symbol";
    symbolCommand.parseCommandFunc = [&](const FuncParams& Params)
    {
        blocksLayouts.back().symbol = FileCommandLoader::readchar(Params);
    };
    fileLoader.addCommand(symbolCommand);  

    // defining color command  
    Command colorCommand;
    colorCommand.command = "fillcolor";
    colorCommand.parseCommandFunc = [&](const FuncParams& Params)
    {
        blocksLayouts.back().color = FileCommandLoader::readColor(Params);
    };
    fileLoader.addCommand(colorCommand);  

    // defining hp command  
    Command hpCommand;
    hpCommand.command = "hp";
    hpCommand.parseCommandFunc = [&](const FuncParams& Params)
    {
        blocksLayouts.back().hp = FileCommandLoader::readint(Params);
    };
    fileLoader.addCommand(hpCommand);  

    // defining width command  
    Command widthCommand;
    widthCommand.command = "width";
    widthCommand.parseCommandFunc = [&](const FuncParams& Params)
    {
        width = FileCommandLoader::readint(Params);
    };
    fileLoader.addCommand(widthCommand);  

    // defining height command  
    Command heightCommand;
    heightCommand.command = "height";
    heightCommand.parseCommandFunc = [&](const FuncParams& Params)
    {
        height = FileCommandLoader::readint(Params);
    };
    fileLoader.addCommand(heightCommand);  

    // defining layout command  
    Command layoutCommand;
    layoutCommand.commandType = COMMAND_MULTI_LINE;
    layoutCommand.command = "layout";
    layoutCommand.parseCommandFunc = [&](const FuncParams& Params)
    {
        
        // AARectangle blockRect = AARectangle(Vec2D(startingPointinX, (Params.lineNum + 1) * BreakOutGameLevel::BLOCK_HEIGHT), BreakOutGameLevel::BLOCK_WIDTH, BreakOutGameLevel::BLOCK_HEIGHT);
        int block_width = App::Singleton().Width()/Params.line.length();
        float startingPointinX = 0;
        AARectangle blockRect = AARectangle(Vec2D(startingPointinX, (Params.lineNum + 1) * BLOCK_HEIGHT), block_width, BLOCK_HEIGHT);
        std::cout<<App::Singleton().Width()<<", "<<Params.line.length()<<std::endl;
        // then loop over columns to initialize each block (rect, blockColor, fillColor)
        for(uint8_t column = 0; column < Params.line.length(); column++)
        {
            if(Params.line[column] != '-')
            {
                LayoutBlock layoutblock = findLayoutBlockForSymbol(blocksLayouts, Params.line[column]);
                Block block;
                block.init(blockRect, layoutblock.hp, Color::Black(), layoutblock.color);
                levelBlocks.push_back(block);
            }
            // blockRect.MoveBy(Vec2D(BLOCK_WIDTH, 0));
            blockRect.MoveBy(Vec2D(block_width, 0));
        }        
    };
    fileLoader.addCommand(layoutCommand);              
    
    fileLoader.loadFile(filePath);

    if(levels.size() > 0)
    {
        levels.back().load(levelBlocks);
    }

    return levels;
}


bool BreakOutGameLevel::isLevelComplete() const
{
    for(auto block : mBlocks)
    {
        if(!block.isDestroyed())
        {
            return false;
        }
    }
    return true;
}



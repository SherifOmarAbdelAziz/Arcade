/*
 * Block.cpp
 *
 *  Created on: May 25, 2024
 *      Author: sherif
 */

#include "Block.h"
#include "Screen.h"
#include "Ball.h"

Block::Block() : mOutlineColor(Color::White()), mFillingColor(Color::White()), mHealthPoints(1)
{

}

void Block::init(const AARectangle& rect, uint8_t healthPoints, Color outFillColor, Color fillColor)
{
    Excluder::Init(rect);
    mHealthPoints = healthPoints;
    mOutlineColor = outFillColor;
    mFillingColor = fillColor;
}

void Block::draw(Screen &screen)
{
    screen.draw(GetAARectangle(), mOutlineColor, true, mFillingColor);
}

void Block::Bounce(Ball &ball, const BoundaryEdge& boundary)
{
    ball.Bounce(boundary);
}
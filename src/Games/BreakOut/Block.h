/*
 * Block.h
 *
 *  Created on: May 25, 2024
 *      Author: sherif
 */


#include "Excluder.h"
#include "Color.h"

class Ball;
class Screen;

class Block : public Excluder
{
    public:
        Block();
        void init(const AARectangle& rect, uint8_t healthPoints, Color outlineColor, Color fillColor);
        void draw(Screen &Screen);
        void Bounce(Ball &ball, const BoundaryEdge& boundary);
        inline void reduceHealthPoints() {if(mHealthPoints > 0) --mHealthPoints;}
        inline uint8_t getHp() const {return mHealthPoints;}
        inline bool isDestroyed() const {return (0 == mHealthPoints);}
        inline const Color& getOutineColor() const {return mOutlineColor;}
        inline const Color& getFillingColor() const {return mFillingColor;}

    private:
        Color mOutlineColor, mFillingColor;
        uint8_t mHealthPoints; // if -1, then block is destroyed
};
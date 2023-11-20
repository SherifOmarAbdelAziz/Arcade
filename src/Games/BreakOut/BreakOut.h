/*
 * BreakOut.h
 *
 *  Created on: Jun 1, 2021
 *      Author: sherif
 */

#ifndef GAMES_BREAKOUT_H_
#define GAMES_BREAKOUT_H_

#include "Game.h"
#include "Paddle.h"
#include "Ball.h"
#include "AARectangle.h"

class BreakOut : public Game {
public:

	virtual void Init(GameController& controller);
	virtual void Update(uint32_t dt);
	virtual void Draw(Screen& mScreen);
	virtual const string& GetName();



private:
	void ResetPaddle();
	Paddle mPaddle;
	Ball mBall;

	static const unsigned int paddle_width = 100;
	static const unsigned int paddle_height = 20;
};

#endif /* GAMES_BREAKOUT_H_ */

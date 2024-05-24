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
#include "LevelBoundary.h"

class BreakOut : public Game {
public:
	virtual void Init(GameController& controller);
	virtual void Update(uint32_t dt);
	virtual void Draw(Screen& screen);
	virtual const string& GetName();

private:
	static const unsigned int paddle_width = 100;
	static const unsigned int paddle_height = 20;

	void ResetGame();
	const Vec2D INITIAL_BALL_VELOCITY = Vec2D(200, -200);
	Paddle mPaddle;
	Ball mBall;
	LevelBoundary mLevelBoundary;
};

#endif /* GAMES_BREAKOUT_H_ */

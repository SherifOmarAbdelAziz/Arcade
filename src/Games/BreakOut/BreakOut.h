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
#include "BreakOutGameLevel.h"

enum GameState
{
	IN_PLAY,
	IN_SERVE,
	GAME_OVER
};

class BreakOut : public Game {
public:
	virtual void Init(GameController& controller);
	virtual void Update(uint32_t dt);
	virtual void Draw(Screen& screen);
	virtual const string& GetName();

private:
	const unsigned int NUM_LIVES = 3;
	static const unsigned int paddle_width = 100;
	static const unsigned int paddle_height = 20;

	inline BreakOutGameLevel& getCurrentLevel() {return mGameLevels[mCurrentLevel];}

	void ResetGame(size_t level=0);
	void setToServe();
	bool checkIfBallPassedPaddle() const;
	inline void reduceLives() {if (mLives >= 0) mLives -= 1;}
	inline bool isGameOver() const {return (mLives < 0);}	
	const float INITIAL_BALL_VELOCITY_FLOAT = 350;
	const Vec2D INITIAL_BALL_VELOCITY = Vec2D(INITIAL_BALL_VELOCITY_FLOAT, -INITIAL_BALL_VELOCITY_FLOAT);
	Paddle mPaddle;
	Ball mBall;
	LevelBoundary mLevelBoundary;
	std::vector<BreakOutGameLevel> mGameLevels;
	size_t mCurrentLevel;
	GameState mGameState;
	short int mLives;	
};

#endif /* GAMES_BREAKOUT_H_ */

/*
 * Paddle.h
 *
 *  Created on: Jun 3, 2021
 *      Author: sherif
 */

#ifndef GAMES_BREAKOUT_PADDLE_H_
#define GAMES_BREAKOUT_PADDLE_H_

#include "Excluder.h"
#include "Screen.h"

enum PaddleDirection {
	//NONE = 0,
	LEFT = 1<<0,
	RIGHT = 1<<1
};

class Paddle : public Excluder {
public:

	void Init(const AARectangle& Rect, const AARectangle& Boundary);
	void update(uint32_t dt);
	void draw(Screen &mScreen);

	inline bool IsMovingLeft() {return mPaddleDirection == PaddleDirection::LEFT;}
	inline bool IsMovingRight() {return mPaddleDirection == PaddleDirection::RIGHT;}

	void SetMovementDirection (const PaddleDirection& Direction) {mPaddleDirection |= Direction;}
	void UnSetMovementDirection (const PaddleDirection& Direction) {mPaddleDirection &= ~Direction;}
	//void StopMovement () {mPaddleDirection = PaddleDirection::NONE;}
	void StopMovement () {
		mPaddleDirection &= (~LEFT & ~RIGHT);
	}

private:
	uint32_t mPaddleDirection;
	const float VELOCITY = 150.0f;

	AARectangle mBoundary;

};

#endif /* GAMES_BREAKOUT_PADDLE_H_ */

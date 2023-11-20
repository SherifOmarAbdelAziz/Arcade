/*
 * Ball.h
 *
 *  Created on: Oct 1, 2021
 *      Author: sherif
 */

#ifndef GAMES_BREAKOUT_BALL_H_
#define GAMES_BREAKOUT_BALL_H_

#include "Vec2D.h"
#include "AARectangle.h"
#include "Screen.h"

struct BoundaryEdge;

class Ball {
public:
	Ball();
	Ball(const Vec2D& pos, float mradius);

	void update(uint32_t dt);
	void draw(Screen& mscreen);

	void MoveTo(const Vec2D &point);
	inline void Stop() {VELOCITY = Vec2D::Zero();}

	inline void SetVelocity(const Vec2D& v) {VELOCITY = v;}
	inline Vec2D GetVelocity() {return VELOCITY;}
	inline Vec2D GetPosition() {return mBox.GetCenterPoint();}
	inline float GetRadius() {return radius;}

	inline const AARectangle GetBoundingRect() {return mBox;}

	void MakeFlushWithEdge(const BoundaryEdge& mBoundaryEdge, Vec2D PointOnEdge,bool LimitToEdge);

private:
	AARectangle mBox;
	Vec2D VELOCITY;

	static const float radius;
};

#endif /* GAMES_BREAKOUT_BALL_H_ */

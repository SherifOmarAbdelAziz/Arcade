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
	inline void Stop() {mVelocity = Vec2D::Zero();}

	inline void SetVelocity(const Vec2D& v) {mVelocity = v;}
	inline Vec2D GetVelocity() const {return mVelocity;}
	inline Vec2D GetPosition() const {return mBox.GetCenterPoint();}
	inline float GetRadius() const {return radius;}

	inline const AARectangle GetBoundingRect() {return mBox;}

	void Bounce(const BoundaryEdge& edge);

	void MakeFlushWithEdge(const BoundaryEdge& mBoundaryEdge, Vec2D& PointOnEdge,bool LimitToEdge);

private:
	AARectangle mBox;
	Vec2D mVelocity;

	static const float radius;
};

#endif /* GAMES_BREAKOUT_BALL_H_ */

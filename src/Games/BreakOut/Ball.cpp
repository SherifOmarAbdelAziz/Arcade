/*
 * Ball.cpp
 *
 *  Created on: Oct 1, 2021
 *      Author: sherif
 */

#include <Ball.h>
#include "Circle.h"
#include "Color.h"
#include "BoundaryEdge.h"
//#include <iostream>

const float Ball::radius = 5.0f;


Ball::Ball() : Ball(Vec2D::Zero(), Ball::radius) {
	// TODO Auto-generated constructor stub

}

Ball::Ball(const Vec2D& pos, float mradius) : VELOCITY(Vec2D::Zero()) {

	mBox = AARectangle(Vec2D(pos.GetVec2Dx(), pos.GetVec2Dy()), radius*2.0F, radius*2.0F);
}

void Ball::update(uint32_t dt) {
	mBox.MoveBy(GetVelocity() * MilliSecondstoSeconds(dt));
}

void Ball::draw(Screen& mscreen) {
	Circle Circ(GetPosition(), GetRadius());
	mscreen.draw(Circ, Color::Red(), true, Color::Red());
}

void Ball::MoveTo(const Vec2D &point) {
	//cout<<point.GetVec2Dx()<< " " << point.GetVec2Dy() <<endl;
	mBox.MoveTo(Vec2D(point.GetVec2Dx()-radius, point.GetVec2Dy()-radius));
}

void Ball::MakeFlushWithEdge(const BoundaryEdge& mBoundaryEdge, Vec2D PointOnEdge,bool LimitToEdge) {
	if (mBoundaryEdge.normal == UP_DIR) {
		mBox.MoveTo(Vec2D(mBox.GetTopLeftPoint().GetVec2Dx(),mBoundaryEdge.Edge.Getmp0().GetVec2Dy()-mBox.GetHeight()));
	}
	else if (mBoundaryEdge.normal == DOWN_DIR) {
		mBox.MoveTo(Vec2D(mBox.GetTopLeftPoint().GetVec2Dx(),mBoundaryEdge.Edge.Getmp0().GetVec2Dy()+mBox.GetHeight()));
	}
	else if (mBoundaryEdge.normal == LEFT_DIR) {
		mBox.MoveTo(Vec2D(mBoundaryEdge.Edge.Getmp0().GetVec2Dx()-mBox.GetWidth(), mBox.GetTopLeftPoint().GetVec2Dy()) );
	}
	else if (mBoundaryEdge.normal == RIGHT_DIR) {
		mBox.MoveTo(Vec2D(mBoundaryEdge.Edge.Getmp0().GetVec2Dx()+mBoundaryEdge.normal.GetVec2Dx(), mBox.GetTopLeftPoint().GetVec2Dy()) );
	}
	PointOnEdge = mBoundaryEdge.Edge.ClosestPoint(mBox.GetCenterPoint(),LimitToEdge);
}


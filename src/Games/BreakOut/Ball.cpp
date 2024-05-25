/*
 * Ball.cpp
 *
 *  Created on: Oct 1, 2021
 *      Author: sherif
 */

#include "Ball.h"
#include "Circle.h"
#include "Color.h"
#include "BoundaryEdge.h"
#include <iostream>

const float Ball::radius = 5.0f;


Ball::Ball() : Ball(Vec2D::Zero(), Ball::radius) {
	// TODO Auto-generated constructor stub

}

Ball::Ball(const Vec2D& pos, float mradius) : mVelocity(Vec2D::Zero()) {

	mBox = AARectangle(Vec2D(pos.GetVec2Dx(), pos.GetVec2Dy()), radius*2.0F, radius*2.0F);
}

void Ball::update(uint32_t dt) {
	mBox.MoveBy(GetVelocity() * MilliSecondstoSeconds(dt));
}

void Ball::draw(Screen& mscreen) {
	Circle circle(GetPosition(), GetRadius());
	mscreen.draw(circle, Color::Red(), true, Color::Red());
}

void Ball::MoveTo(const Vec2D &point) {
	//cout<<point.GetVec2Dx()<< " " << point.GetVec2Dy() <<endl;
	mBox.MoveTo(Vec2D(point.GetVec2Dx()-radius, point.GetVec2Dy()-radius));
}

void Ball::MakeFlushWithEdge(const BoundaryEdge& edge, Vec2D& PointOnEdge, bool LimitToEdge) {
	if (edge.normal == UP_DIR) {
		// mBox.MoveTo(Vec2D(mBox.GetTopLeftPoint().GetVec2Dx(), edge.edge.Getmp0().GetVec2Dy()+mBox.GetHeight()));
		mBox.MoveTo(Vec2D(mBox.GetTopLeftPoint().GetVec2Dx(), edge.edge.Getmp0().GetVec2Dy()-mBox.GetHeight()));
	}
	else if (edge.normal == DOWN_DIR) {
		// mBox.MoveTo(Vec2D(mBox.GetTopLeftPoint().GetVec2Dx(), mBox.GetBottomRightPoint().GetVec2Dy()-mBox.GetHeight()));
		mBox.MoveTo(Vec2D(mBox.GetTopLeftPoint().GetVec2Dx(), edge.edge.Getmp0().GetVec2Dy()+mBox.GetHeight()));
	}
	else if (edge.normal == LEFT_DIR) {
		// mBox.MoveTo(Vec2D(edge.edge.Getmp0().GetVec2Dx()+mBox.GetWidth(), mBox.GetTopLeftPoint().GetVec2Dy()) );
		mBox.MoveTo(Vec2D(edge.edge.Getmp0().GetVec2Dx()-mBox.GetWidth(), mBox.GetTopLeftPoint().GetVec2Dy()) );
	}
	else if (edge.normal == RIGHT_DIR) {
		// mBox.MoveTo(Vec2D(edge.edge.Getmp0().GetVec2Dx()+ edge.normal.GetVec2Dx(), mBox.GetTopLeftPoint().GetVec2Dy()) );
		// mBox.MoveTo(Vec2D(mBox.GetTopLeftPoint().GetVec2Dx()-mBox.GetWidth(), mBox.GetTopLeftPoint().GetVec2Dy()) );
		mBox.MoveTo(Vec2D(mBox.GetTopLeftPoint().GetVec2Dx()+mBox.GetWidth(), mBox.GetTopLeftPoint().GetVec2Dy()) );
	}
	PointOnEdge = edge.edge.ClosestPoint(mBox.GetCenterPoint(),LimitToEdge);
}

void Ball::Bounce(const BoundaryEdge& edge)
{
	Vec2D pointOnEdge;

	MakeFlushWithEdge(edge, pointOnEdge, false);
	
	mVelocity = mVelocity.Reflect(edge.normal);
}
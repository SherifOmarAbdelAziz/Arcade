/*
 * Paddle.cpp
 *
 *  Created on: Jun 3, 2021
 *      Author: sherif
 */

#include "Paddle.h"
#include <cassert>
#include "Color.h"


void Paddle::Init(const AARectangle& Rect, const AARectangle& Boundary) {
	Excluder::Init(Rect);
	//mPaddleDirection = PaddleDirection::NONE;
	StopMovement();
	mBoundary = Boundary;
}

void Paddle::update(uint32_t dt, Ball& ball) 
{
	if(GetAARectangle().ContainsPoint(ball.GetPosition()))
	{
		Vec2D pointOnEdge;
		ball.MakeFlushWithEdge(GetBoundaryEdge(BOTTOM_EDGE), pointOnEdge, true);
	}

	if(mPaddleDirection) 
	{
		Vec2D dir(0,0);

		if ((mPaddleDirection == (PaddleDirection::RIGHT | PaddleDirection::LEFT))) {
			dir = Vec2D(0,0);
		}

		else if(mPaddleDirection == PaddleDirection::LEFT) {
			dir = LEFT_DIR;
			//cout<<"Moving left"<<endl;
		}
		else if (mPaddleDirection == PaddleDirection::RIGHT) {
			dir = RIGHT_DIR;
			//cout<<"Moving right"<<endl;
		}

		Vec2D dx = dir * VELOCITY * (float)MilliSecondstoSeconds(dt);
		//cout<<"direction = "<<dir.GetVec2Dx()<<","<< dir.GetVec2Dy()<<endl;
		MoveBy(dx);

		const AARectangle& paddleBoundary = GetAARectangle();

		if (IsGreaterThanOrEqual(mBoundary.GetTopLeftPoint().GetVec2Dx(), paddleBoundary.GetTopLeftPoint().GetVec2Dx()))
		{
			Vec2D x = Vec2D(mBoundary.GetTopLeftPoint().GetVec2Dx(), paddleBoundary.GetTopLeftPoint().GetVec2Dy());
			MoveTo(x);
		}
		else if (IsGreaterThanOrEqual(paddleBoundary.GetBottomRightPoint().GetVec2Dx(), mBoundary.GetBottomRightPoint().GetVec2Dx()))
		{
			Vec2D x = Vec2D(mBoundary.GetBottomRightPoint().GetVec2Dx()-paddleBoundary.GetWidth(), paddleBoundary.GetTopLeftPoint().GetVec2Dy());
			MoveTo(x);
		}

	}
}

void Paddle::draw(Screen &mScreen) {
	//AARectangle myRectangle(Vec2D(GetAARectangle().GetTopLeftPoint().GetVec2Dx(), GetAARectangle().GetTopLeftPoint().GetVec2Dy()),
	//		GetAARectangle().GetWidth(), GetAARectangle().GetHeight());

	//cout<<myRectangle.GetTopLeftPoint().GetVec2Dx()<<", "<<myRectangle.GetTopLeftPoint().GetVec2Dy()<<endl;
	mScreen.draw(GetAARectangle(), Color::Blue(), true, Color::Blue());
}


bool Paddle::Bounce(Ball& ball)
{		
	bool retVal = false;
	BoundaryEdge edge;
	// check if collided with ball
	if(HasCollided(ball.GetBoundingRect(), edge))
	{
		// if collided, then flush intersection		
		Vec2D pointOnEdge;
		ball.MakeFlushWithEdge(edge, pointOnEdge, true);
		if(edge.edge == GetBoundaryEdge(UPPER_EDGE).edge)
		{
			// then check percentage of collision on edge
			float edgeLength = edge.edge.Length();
			assert(!IsEqual(edgeLength, 0));
			float tx = (pointOnEdge.GetVec2Dx() - edge.edge.Getmp0().GetVec2Dx())/edgeLength;

			if((tx <= CORNER_BOUNCE_AMT && ball.GetVelocity().GetVec2Dx() > 0)
				|| (tx >= (1.0f - CORNER_BOUNCE_AMT) && (ball.GetVelocity().GetVec2Dx() < 0)))
			{
				ball.SetVelocity(ball.GetVelocity() * -1);
				// ball.SetVelocity(ball.GetVelocity().Reflect(edge.normal));	
				retVal = true;
			}
		}

		ball.SetVelocity(ball.GetVelocity().Reflect(edge.normal));
		retVal = true;

	}
	return retVal;
}

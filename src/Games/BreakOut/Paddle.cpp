/*
 * Paddle.cpp
 *
 *  Created on: Jun 3, 2021
 *      Author: sherif
 */

#include <Paddle.h>
#include "Color.h"
//#include <iostream>

void Paddle::Init(const AARectangle& Rect, const AARectangle& Boundary) {
	Excluder::Init(Rect);
	//mPaddleDirection = PaddleDirection::NONE;
	StopMovement();
	mBoundary = Boundary;
}

void Paddle::update(uint32_t dt) {

	if(mPaddleDirection) {
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




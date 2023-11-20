/*
 * BreakOut.cpp
 *
 *  Created on: Jun 1, 2021
 *      Author: sherif
 */

#include <BreakOut.h>
#include <iostream>
#include "App.h"

void BreakOut::Init(GameController& controller) {
	//cout<<"BreakOut Init"<<endl;
	ResetPaddle();
	ButtonAction action;
	action.Key = GameController::left();
	action.Action = [this](uint32_t dt, inputState state) {
		if (GameController::IsPressed(state)) {
			//cout<< "01: Key is pressed : "<<state<<endl;
			mPaddle.SetMovementDirection (PaddleDirection::LEFT);
		}
		else {
			//cout<< "02: Key is released : "<<state<<endl;
			mPaddle.UnSetMovementDirection (PaddleDirection::LEFT);
		}
	};
	controller.AddActionForKey(action);

	action.Key = GameController::right();
	action.Action = [this](uint32_t dt, inputState state) {
		if (GameController::IsPressed(state)) {
			//cout<< "Key is pressed : "<<state<<endl;
			mPaddle.SetMovementDirection (PaddleDirection::RIGHT);
		}
		else {
			mPaddle.UnSetMovementDirection (PaddleDirection::RIGHT);
		}
	};
	controller.AddActionForKey(action);
}

void BreakOut::Update(uint32_t dt) {
	mPaddle.update(dt);
	mBall.update(dt);
	//cout<<"BreakOut Update"<<endl;
}

void BreakOut::Draw(Screen& mScreen) {
	mPaddle.draw(mScreen);
	mBall.draw(mScreen);
	//cout<<"BreakOut Draw"<<endl;
}

const string& BreakOut::GetName() {
	static string name = "BreakOut!";
	return name;
}

void BreakOut::ResetPaddle() {

	Vec2D TopLeft, BottomRight;
	TopLeft = Vec2D( (App::Singleton().Width()/2) - (paddle_width/2), App::Singleton().Height()-(3*paddle_height) );
	AARectangle rect(TopLeft, paddle_width, paddle_height);

	AARectangle GameBoundary = AARectangle(Vec2D(0,0) , App::Singleton().Width(), App::Singleton().Height());
	mPaddle.Init(rect, GameBoundary);
	mBall.MoveTo(Vec2D(App::Singleton().Width()/2, App::Singleton().Height()/2));
}

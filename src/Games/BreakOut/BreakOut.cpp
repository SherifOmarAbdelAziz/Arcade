/*
 * BreakOut.cpp
 *
 *  Created on: Jun 1, 2021
 *      Author: sherif
 */

#include <BreakOut.h>
#include <iostream>
#include "App.h"
#include "Circle.h"
#include "Line.h"

void BreakOut::Init(GameController& controller) 
{
	//cout<<"BreakOut Init"<<endl;
	ResetGame();
	
	ButtonAction action;
	
	action.Key = GameController::ActionKey();
	action.Action = [this](uint32_t dt, inputState state)
	{
		switch(mGameState)
		{
			case IN_SERVE:
				if (GameController::IsPressed(state)) 
				{
					mGameState = IN_PLAY;
					if(mPaddle.IsMovingLeft())
					{
						mBall.SetVelocity(Vec2D(-1*INITIAL_BALL_VELOCITY_FLOAT, -1*INITIAL_BALL_VELOCITY_FLOAT));
					}
					else
					{
						mBall.SetVelocity(Vec2D(INITIAL_BALL_VELOCITY_FLOAT, -1*INITIAL_BALL_VELOCITY_FLOAT));
					}
				}
				break;
			case GAME_OVER:
				if (GameController::IsPressed(state)) 
				{
					ResetGame();
				}			
				break;
		}
	};
	controller.AddActionForKey(action);

	action.Key = GameController::left();
	action.Action = [this](uint32_t dt, inputState state) 
	{
		if(GAME_OVER != mGameState)
		{
			if (GameController::IsPressed(state)) 
			{
				//cout<< "01: Key is pressed : "<<state<<endl;
				mPaddle.SetMovementDirection (PaddleDirection::LEFT);
			}
			else 
			{
				//cout<< "02: Key is released : "<<state<<endl;
				mPaddle.UnSetMovementDirection (PaddleDirection::LEFT);
			}
		}
	};
	controller.AddActionForKey(action);

	action.Key = GameController::right();
	action.Action = [this](uint32_t dt, inputState state) 
	{
		if(GAME_OVER != mGameState)
		{
			if (GameController::IsPressed(state)) 
			{
				//cout<< "Key is pressed : "<<state<<endl;
				mPaddle.SetMovementDirection (PaddleDirection::RIGHT);
			}
			else 
			{
				mPaddle.UnSetMovementDirection (PaddleDirection::RIGHT);
			}			
		}		
	};
	controller.AddActionForKey(action);
}

void BreakOut::Update(uint32_t dt) 
{
	mPaddle.update(dt, mBall);
	
	BoundaryEdge edge;

	switch(mGameState)
	{
		case IN_SERVE:
			setToServe();
			break;
		case IN_PLAY:
			mBall.update(dt);
			if(mPaddle.Bounce(mBall))
			{
				return;
			}

			if (mLevelBoundary.HasCollided(mBall, edge))
			{
				// mBall.Stop();
				mBall.Bounce(edge);
				return;
			}
			// mGameLevel.update(dt, mBall);
			getCurrentLevel().update(dt, mBall);

			if(checkIfBallPassedPaddle())
			{
				reduceLives();
				if(isGameOver())
				{
					mGameState = GAME_OVER;
				}
				else
				{
					setToServe();					
				}
			}
			else if(getCurrentLevel().isLevelComplete())
			{
				mCurrentLevel = (mCurrentLevel+1) % mGameLevels.size();
				ResetGame(mCurrentLevel);
				setToServe();
			}
			break;

		// case GAME_OVER:	
		// 	mBall.Stop();
		// 	mPaddle.StopMovement();
		// 	break;
	}
	// cout<<"BreakOut Update"<<endl;
}

void BreakOut::Draw(Screen& screen) 
{
	mPaddle.draw(screen);
	mBall.draw(screen);
	screen.draw(mLevelBoundary.GetAARectangle(), Color::White(), false, Color::Black());
	// mGameLevel.draw(screen);
	getCurrentLevel().draw(screen);

	// Line cutOffLine = Line();

	// cutOffLine.Setmp0(Vec2D(0, mPaddle.GetAARectangle().GetBottomRightPoint().GetVec2Dy()));
	// cutOffLine.Setmp1(Vec2D(App::Singleton().Width(), mPaddle.GetAARectangle().GetBottomRightPoint().GetVec2Dy()));

	// screen.draw(cutOffLine, Color::White());

	int lifeRadius = 8;
	for(int index = 0; index<mLives; index++)
	{
		Circle life = Circle(Vec2D(17, App::Singleton().Height() - 15), lifeRadius);
		life.MoveBy(Vec2D((lifeRadius*2+4)*index, 0));
		screen.draw(life, Color::Green(), true, Color::Green());
	}
	//cout<<"BreakOut Draw"<<endl;
}

const string& BreakOut::GetName() 
{
	static string name = "BreakOut!";
	return name;
}

void BreakOut::ResetGame(size_t level) 
{
	mLives = NUM_LIVES;
	mGameLevels = BreakOutGameLevel::loadLevelsFromFile(App::getBasePath() + "../../src/Assets/BreakoutLevels.txt");
	mCurrentLevel = level;

	Vec2D TopLeft = Vec2D( (App::Singleton().Width()/2) - (paddle_width/2), App::Singleton().Height()-(3*paddle_height) );
	AARectangle paddleBoundary(TopLeft, paddle_width, paddle_height);
	AARectangle GameBoundary = AARectangle(Vec2D::Zero(), App::Singleton().Width(), App::Singleton().Height());
	
	mLevelBoundary = GameBoundary;
	
	// BreakOutGameLevel mGameLevel;
	// mGameLevels.push_back(mGameLevel);
	// mGameLevels[0].init(GameBoundary);
	mPaddle.Init(paddleBoundary, GameBoundary);
	// mBall.MoveTo(Vec2D(App::Singleton().Width()/2, App::Singleton().Height()/2));
	// mBall.MoveTo(Vec2D(App::Singleton().Width()/2, App::Singleton().Height()*0.75));
	setToServe();
}

void BreakOut::setToServe()
{
	mGameState = IN_SERVE;
	mBall.Stop();
	mBall.MoveTo(Vec2D(mPaddle.GetAARectangle().GetCenterPoint().GetVec2Dx(), mPaddle.GetAARectangle().GetTopLeftPoint().GetVec2Dy()-mBall.GetRadius()-1));
}

bool BreakOut::checkIfBallPassedPaddle() const
{
	bool retVal = false;
	if(mBall.GetBoundingRect().GetTopLeftPoint().GetVec2Dy() > mPaddle.GetAARectangle().GetBottomRightPoint().GetVec2Dy())
	{
		retVal = true;
	}
	return retVal;
}


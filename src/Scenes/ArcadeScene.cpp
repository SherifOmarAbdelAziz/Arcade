/*
 * ArcadeScene.cpp
 *
 *  Created on: Apr 10, 2021
 *      Author: sherif
 */

#include "ArcadeScene.h"
#include "GameController.h"

ArcadeScene::~ArcadeScene() {
	// TODO Auto-generated destructor stub
}

void ArcadeScene::Init() {

	//mGameController = new GameController;
	ButtonAction action;
	action.Key = GameController::ActionKey();
	action.Action = [](uint32_t dt, inputState state) {
		if (GameController::IsPressed(state)) {
			cout<< "Key is pressed : "<<state<<endl;
		}
	};
	mGameController.AddActionForKey(action);

	MouseButtonActionStruct action_mouse;
	action_mouse.input_Mouse_Button = GameController::LeftMouseButton();
	action_mouse.Mouse_Button_Action = [](inputState state, const MousePosition& MousePos){
		if (GameController::IsPressed(state))
			cout<< "Mouse is pressed : "<<state<<endl;
	};
	mGameController.AddMouseActionForMouseButton(action_mouse);

	MouseMoveAction move_mouse;
	move_mouse = [](const MousePosition& MousePos){cout<<"Mouse Moved to : "<<MousePos.pos_x<< ", " <<MousePos.pos_y<<endl;};
	mGameController.SetActionforMouseMoveAction(move_mouse);
}

void ArcadeScene::update(uint32_t dt) {

}

void ArcadeScene::draw(Screen& mScreen) {
	//Circle Circ(Vec2D(mScreen.width()/2+50,mScreen.height()/2+50), 50.0);
	//AARectangle rect(Vec2D(mScreen.width()/2-25,mScreen.height()/2-25), 50, 50);

	//mScreen.draw(rect, Color::Blue(), true, Color::Blue());
	//mScreen.draw(Circ, Color(0,255,0,150), true, Color(0,255,0,150));
}

const string& ArcadeScene::GetSceneName() const {
	static string ArcadeSceneName = "Sherif's Arcade App";
	return ArcadeSceneName;
}

unique_ptr<ArcadeScene> ArcadeScene::GetScene(Gamename eGame) {
	switch (eGame) {
		case Tetris: {} break;

		case Pacman: {} break;
	}
	return nullptr;
}


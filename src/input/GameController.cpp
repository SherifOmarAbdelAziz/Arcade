/*
 * GameController.cpp
 *
 *  Created on: May 2, 2021
 *      Author: sherif
 */

#include "GameController.h"

GameController::GameController() : mMouseMoveAction(nullptr) {
	// TODO Auto-generated constructor stub

}

inputAction GameController::GetActionForKey(inputKey Key) {
//	if (mButtonActions.empty()) {
//		return [](uint32_t dt, inputState state){};
//	}

	for (auto button : mButtonActions) {
		if (button.Key == Key) {
			return button.Action;
		}
	}
	return [](uint32_t dt, inputState state){};
}

void GameController::AddActionForKey(const ButtonAction& KeyAction) {
	mButtonActions.push_back(KeyAction);
}

bool GameController::IsPressed(inputState state) {
	return (state == SDL_PRESSED);
}

bool GameController::IsReleased(inputState state) {
	return (state == SDL_RELEASED);
}

inputKey GameController::ActionKey() {
	return static_cast<inputKey>(SDLK_a);
}

inputKey GameController::CancelKey() {
	return static_cast<inputKey>(SDLK_s);
}

inputKey GameController::left() {
	return static_cast<inputKey>(SDLK_LEFT);
}

inputKey GameController::right() {
	return static_cast<inputKey>(SDLK_RIGHT);
}

inputKey GameController::up() {
	return static_cast<inputKey>(SDLK_UP);
}

inputKey GameController::down() {
	return static_cast<inputKey>(SDLK_DOWN);
}

MouseButtonAction GameController::GetMouseActionforMouseButton(const inputMouseButton& input) {
	for (auto Mousebutton : mMouseButtonActions) {
		if(Mousebutton.input_Mouse_Button == input) {
			return Mousebutton.Mouse_Button_Action;
		}
	}

	return [](inputState state, MousePosition MousePos){};
}

void GameController::AddMouseActionForMouseButton(const MouseButtonActionStruct& ButtonAction) {
	mMouseButtonActions.push_back(ButtonAction);
}

inputMouseButton GameController::LeftMouseButton() {
	return static_cast<inputMouseButton>(SDL_BUTTON_LEFT);
}
inputMouseButton GameController::RightMouseButton() {
	return static_cast<inputMouseButton>(SDL_BUTTON_RIGHT);
}

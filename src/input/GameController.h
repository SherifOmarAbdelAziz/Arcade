/*
 * GameController.h
 *
 *  Created on: May 2, 2021
 *      Author: sherif
 */

#ifndef INPUT_GAMECONTROLLER_H_
#define INPUT_GAMECONTROLLER_H_

#include <vector>
#include "inputAction.h"
#include <SDL2/SDL.h>

using namespace std;

class GameController {
public:
	GameController();
	inputAction GetActionForKey(inputKey Key);
	void AddActionForKey(const ButtonAction& KeyAction);

	inline MouseMoveAction GetActionforMouseMoveAction() {return mMouseMoveAction;}
	inline void SetActionforMouseMoveAction(const MouseMoveAction& MoveAction) {mMouseMoveAction = MoveAction;}
	MouseButtonAction GetMouseActionforMouseButton(const inputMouseButton& input);
	void AddMouseActionForMouseButton(const MouseButtonActionStruct& ButtonAction);

	static bool IsPressed(inputState state);
	static bool IsReleased(inputState state);
	static inputKey ActionKey();
	static inputKey CancelKey();
	static inputKey left();
	static inputKey right();
	static inputKey up();
	static inputKey down();

	static inputMouseButton LeftMouseButton();
	static inputMouseButton RightMouseButton();

private:
	vector<ButtonAction> mButtonActions;
	vector<MouseButtonActionStruct> mMouseButtonActions;
	MouseMoveAction mMouseMoveAction;
};

#endif /* INPUT_GAMECONTROLLER_H_ */

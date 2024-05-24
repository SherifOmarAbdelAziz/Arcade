/*
 * InputController.h
 *
 *  Created on: May 4, 2021
 *      Author: sherif
 */

#ifndef INPUT_INPUTCONTROLLER_H_
#define INPUT_INPUTCONTROLLER_H_


#include "GameController.h"


class InputController {
public:
	InputController();
	void Init(inputAction Q);
	void update(uint32_t dt);
	void SetInputController (GameController* GController);

private:
	inputAction mQuit;
	GameController* mptrGameController;
};

#endif /* INPUT_INPUTCONTROLLER_H_ */

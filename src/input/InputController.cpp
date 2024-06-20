/*
 * InputController.cpp
 *
 *  Created on: May 4, 2021
 *      Author: sherif
 */

#include <InputController.h>
#include <iostream>
using namespace std;

InputController::InputController() : mQuit(nullptr), mptrGameController(nullptr) {
	// TODO Auto-generated constructor stub

}

void InputController::Init(inputAction Q) {
	mQuit = Q;
}

void InputController::update(uint32_t dt) {

	SDL_Event event;

	while(SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_QUIT:
					mQuit(dt, SDL_PRESSED);
				break;
			case SDL_KEYUP:
			case SDL_KEYDOWN:
				if (mptrGameController) {
					//cout<<"pushed"<<endl;
					inputAction action = mptrGameController->GetActionForKey(event.key.keysym.sym);
					action(dt, event.key.state);
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
				if (mptrGameController) {
					//cout<<"pushed"<<endl;
					MousePosition M_POS;
					M_POS.pos_x = event.button.x;
					M_POS.pos_y = event.button.y;
					MouseButtonAction action_mouse = mptrGameController->GetMouseActionforMouseButton(event.button.button);
					action_mouse(event.button.state, M_POS);
				}
				break;
			case SDL_MOUSEMOTION:
				if (mptrGameController) {
					if(MouseMoveAction MouseMoved = mptrGameController->GetActionforMouseMoveAction()) {
						MousePosition Mouse_POS;
						Mouse_POS.pos_x = event.motion.x;
						Mouse_POS.pos_y = event.motion.y;;
						MouseMoved(Mouse_POS);
					}
				}
				break;
		}
	}
}

void InputController::SetInputController (GameController* GController) {
	mptrGameController = GController;
}

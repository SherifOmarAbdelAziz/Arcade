/*
 * App.h
 *
 *  Created on: Apr 3, 2021
 *      Author: sherif
 */

#ifndef APP_APP_H_
#define APP_APP_H_

#include <SDL2/SDL.h>
#include <memory>
#include <iostream>
// #include "Color.h"
// #include "Line.h"
// #include "Triangle.h"
// #include "AARectangle.h"
// #include "Circle.h"
// #include "Screen.h"
#include "Scene.h"
#include "InputController.h"

using namespace std;

class App {
public:
	static App& Singleton();
	bool Init(int mWidth, int mHeight, int mag);
	void Run();
	uint32_t Width() {
		return mScreen.width();
	}
	uint32_t Height() {
		return mScreen.height();
	}

	void PushScene (unique_ptr<Scene> scene);
	void PopScene ();
	Scene* TopScene();


private:
	Screen mScreen;
	SDL_Window* mWindow;
	InputController CurrentInputController;
	vector<unique_ptr<Scene>> SceneStack;
};

#endif /* APP_APP_H_ */

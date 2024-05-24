/*
 * App.cpp
 *
 *  Created on: Apr 3, 2021
 *      Author: sherif
 */

#include <memory.h>
#include <iostream>
#include "App.h"
#include "ArcadeScene.h"
#include "BreakOut.h"
#include "GameScene.h"

using namespace std;

App& App::Singleton() {
		static App theApp;
		return theApp;
}

bool App::Init(int mWidth, int mHeight, int mag) {

	unique_ptr<ArcadeScene> Arcade = make_unique<ArcadeScene>();
	mWindow = mScreen.init(mWidth, mHeight, mag);
	Arcade->Init();
	PushScene(move(Arcade));

	//temp
	{
		unique_ptr<BreakOut> mBreakOut = make_unique<BreakOut>();
		unique_ptr<GameScene> mGameScene = make_unique<GameScene>(move(mBreakOut));
		PushScene(move(mGameScene));
	}
	return mWindow != nullptr;
}

void App::Run() {

	uint32_t dt = 10;
	uint32_t lastTick = SDL_GetTicks();
	uint32_t CurrentTick = lastTick;
	uint32_t FrameTime = 0;
	uint32_t Accumulator = 0;


    bool running = true;
    CurrentInputController.Init([&running](uint32_t dt, uint8_t state){running = false;});

    while(running) 
	{
    	CurrentTick = SDL_GetTicks();
    	FrameTime = CurrentTick - lastTick;
    	if (FrameTime > 300)
    		FrameTime = 300;
    	lastTick = CurrentTick;
    	Accumulator += FrameTime;

    	Scene *topScene = App::TopScene();
    	if (topScene) {
			// input
    		CurrentInputController.update(dt);

			// Update
			if (Accumulator >= dt) {
				topScene->update(dt);
				Accumulator -= dt;
			}
			// Render
			topScene->draw(mScreen);
    	}
    	mScreen.SwapScreen();
    }
	cout << "GAME OVER!!!" << endl; // prints !!!Hello World!!!
}


void App::PushScene (unique_ptr<Scene> scene) {
	scene->Init();
	if(scene->GetGameController()) {
		//cout<<"it is not null "<<endl;
	}
	CurrentInputController.SetInputController(scene->GetGameController());
	SceneStack.emplace_back(move(scene));
	SDL_SetWindowTitle(mWindow , TopScene()->GetSceneName().c_str());
}

void App::PopScene () {
	if (SceneStack.size() > 1) {
		SceneStack.pop_back();
	}
	CurrentInputController.SetInputController(TopScene()->GetGameController());
	SDL_SetWindowTitle(mWindow , TopScene()->GetSceneName().c_str());
}

Scene* App::TopScene() {
	if (SceneStack.empty())
		return nullptr;
	else
		return SceneStack.back().get();
}

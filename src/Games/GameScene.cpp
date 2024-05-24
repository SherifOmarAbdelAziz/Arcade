/*
 * GameScene.cpp
 *
 *  Created on: May 31, 2021
 *      Author: sherif
 */

#include "GameScene.h"

GameScene::GameScene(unique_ptr<Game> myGame) : mGame{move(myGame)} {
	// TODO Auto-generated constructor stub

}

void GameScene::Init() {
	//mGameController = new GameController;
	mGame->Init(mGameController);
}

void GameScene::update(uint32_t dt) {
	mGame->Update(dt);
}

void GameScene::draw(Screen& mScreen) {
	mGame->Draw(mScreen);
}

const string& GameScene::GetSceneName() const {
	return mGame->GetName();
}

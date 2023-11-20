/*
 * GameScene.h
 *
 *  Created on: May 31, 2021
 *      Author: sherif
 */

#ifndef GAMES_GAMESCENE_H_
#define GAMES_GAMESCENE_H_

#include "Scene.h"
#include <memory>
#include "Game.h"

class GameScene : public Scene {
public:
	GameScene(unique_ptr<Game> myGame);
	virtual void Init();
	virtual void update(uint32_t dt) override;
	virtual void draw(Screen& mScreen) override;
	virtual const string& GetSceneName() const override;

private:
	unique_ptr<Game> mGame;
};

#endif /* GAMES_GAMESCENE_H_ */

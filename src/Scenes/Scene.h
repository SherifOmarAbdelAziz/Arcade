/*
 * Scene.h
 *
 *  Created on: Apr 10, 2021
 *      Author: sherif
 */

#ifndef SCENES_SCENE_H_
#define SCENES_SCENE_H_

#include "Screen.h"
#include "GameController.h"

class Scene {
public:
	virtual ~Scene() {}
	virtual void Init() = 0;
	virtual void update(uint32_t dt) = 0;
	virtual void draw(Screen& mScreen) = 0;
	virtual const string& GetSceneName() const = 0;

	GameController* GetGameController () {return &mGameController;}

protected:
	GameController mGameController;

};

#endif /* SCENES_SCENE_H_ */

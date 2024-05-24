/*
 * ArcadeScene.h
 *
 *  Created on: Apr 10, 2021
 *      Author: sherif
 */

#ifndef SCENES_ARCADESCENE_H_
#define SCENES_ARCADESCENE_H_
#include "Scene.h"

#include <memory>

enum Gamename {
	Tetris = 0,
	Pacman
};

class ArcadeScene : public Scene {
public:
	virtual ~ArcadeScene();
	virtual void Init() override;
	virtual void update(uint32_t dt) override;
	virtual void draw(Screen& mScreen) override;
	virtual const string& GetSceneName() const override;

private:
	std::unique_ptr<ArcadeScene> GetScene(Gamename eGame);
	//GameController GControl;
};

#endif /* SCENES_ARCADESCENE_H_ */

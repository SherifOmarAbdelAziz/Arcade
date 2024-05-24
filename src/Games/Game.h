/*
 * Game.h
 *
 *  Created on: May 31, 2021
 *      Author: sherif
 */

#ifndef GAMES_GAME_H_
#define GAMES_GAME_H_

#include <string>
using namespace std;
#include "GameController.h"

class Screen;

class Game {
public:
	virtual ~Game() {};
	virtual void Init(GameController& controller) = 0;
	virtual void Update(uint32_t dt) = 0;
	virtual void Draw(Screen&) = 0;
	virtual const string& GetName() = 0;
};

#endif /* GAMES_GAME_H_ */

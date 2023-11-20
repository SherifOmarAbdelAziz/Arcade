/*
 * Screen.h
 *
 *  Created on: Jan 16, 2021
 *      Author: sherif
 */


#ifndef GRAPHICS_SCREEN_H_
#define GRAPHICS_SCREEN_H_

#include <SDL2/SDL.h>
#include "Color.h"
#include "ScreenBuffer.h"
#include "Line.h"
#include "Triangle.h"
#include "AARectangle.h"
#include "Circle.h"
#include "Vec2D.h"
#include <vector>

class Screen {
public:
	Screen();
	~Screen();
	SDL_Window* init (uint32_t w, uint32_t h, uint32_t mag);
	void SwapScreen();

	void draw(uint32_t x, uint32_t y, Color mColor);
	void draw(Line mLine, Color mColor);
	void draw(Triangle Tri, Color mColor, bool fillColor, Color Colorfilling);
	void draw(AARectangle rect, Color mColor, bool fillColor, Color Colorfilling);
	void draw(Circle myCircle, Color mColor, bool fillColor, Color Colorfilling);
	void FillPoly(vector<Vec2D> points, Color mColor);

	uint32_t width() {
		return mwidth;
	}
	uint32_t height() {
		return mheight;
	}

private:
	uint32_t mwidth;
	uint32_t mheight;

	SDL_Window *window;
	SDL_Surface *image;

	ScreenBuffer mBackBuffer;
	Color mClearColor;

	void ClearScreen();
	Screen(const Screen &other);

};

#endif /* GRAPHICS_SCREEN_H_ */

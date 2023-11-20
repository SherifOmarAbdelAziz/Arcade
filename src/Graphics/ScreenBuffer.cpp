/*
 * ScreenBuffer.c
 *
 *  Created on: Jan 9, 2021
 *      Author: sherif
 */

#include "ScreenBuffer.h"

ScreenBuffer::ScreenBuffer() {
	mSurface = nullptr;
}

ScreenBuffer::ScreenBuffer (const ScreenBuffer& screenBuffer) {
	// mSurface = screenBuffer.mSurface; //fuck that, it is shallow copy plus this is a constructor, u need
	// to create a surface u idiot
	mSurface = SDL_CreateRGBSurfaceWithFormat (0, screenBuffer.mSurface->w, screenBuffer.mSurface->h, 0, screenBuffer.mSurface->format->format);
	// copy from src to destination
	SDL_BlitSurface(screenBuffer.mSurface, 0, mSurface, 0);
}
ScreenBuffer::~ScreenBuffer() {

}

void ScreenBuffer::SetPixel(const Color& color, uint32_t x, uint32_t y) {

	uint32_t *pixels = (uint32_t *)mSurface->pixels;
	size_t index = GetIndex(y, x);

	Color surfaceColor = Color(pixels[index]);
	pixels[index] = Color::AlphaBending(color, surfaceColor).GetPixelColor();

	//pixels[index] = color.GetPixelColor();

}
void ScreenBuffer::Clear(const Color& c) {
	SDL_FillRect(mSurface, nullptr, c.GetPixelColor());
}

void ScreenBuffer::Init (uint32_t format, uint32_t w, uint32_t h) {
	mSurface  = SDL_CreateRGBSurfaceWithFormat (0, w, h, 0, format);
	Clear(Color::Black());
}

const ScreenBuffer& ScreenBuffer::operator= (const ScreenBuffer &screenBuffer) {
	if (this == &screenBuffer) {
		return *this;
	}
	if (!mSurface) {
		SDL_FreeSurface(mSurface);
		mSurface = nullptr;
	}
	if (screenBuffer.mSurface != nullptr) {
		mSurface = SDL_CreateRGBSurfaceWithFormat (0, screenBuffer.mSurface->w, screenBuffer.mSurface->h, 0, screenBuffer.mSurface->format->format);
		// copy from src to destination
		SDL_BlitSurface(screenBuffer.mSurface, 0, mSurface, 0);
	}
	return *this;
}






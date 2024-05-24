



#include "Color.h"
#include <SDL2/SDL.h>

const SDL_PixelFormat * Color::mFormat = nullptr;

void Color::InitColorFormat(const SDL_PixelFormat * format){
	Color::mFormat = format;
}

void Color::SetRGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
	mColor = SDL_MapRGBA(Color::mFormat, red, green, blue, alpha);
}

Color::Color (uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
	SetRGBA(r, g, b, a);
}

void Color::SetRed(uint8_t red) {

	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(mColor, Color::mFormat, &r, &g ,&b, &a);
	SetRGBA(red, g, b, a);
}
void Color::SetGreen(uint8_t green){
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(mColor, Color::mFormat, &r, &g ,&b, &a);
	SetRGBA(r, green, b, a);
}
void Color::SetBlue(uint8_t blue) {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	SDL_GetRGBA(mColor, Color::mFormat, &r, &g ,&b, &a);
	SetRGBA(r, g, blue, a);
}
void Color::SetAlpha(uint8_t alpha) {
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t a;
	SDL_GetRGBA(mColor, Color::mFormat, &r, &g ,&b, &a);
	SetRGBA(r, g, b, alpha);
}

uint8_t Color::GetRed() const {
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t a;
	SDL_GetRGBA(mColor, Color::mFormat, &r, &g ,&b, &a);
	return r;

}
uint8_t Color::GetGreen() const {
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t a;
	SDL_GetRGBA(mColor, Color::mFormat, &r, &g ,&b, &a);
	return g;
}
uint8_t Color::GetBlue() const {
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t a;
	SDL_GetRGBA(mColor, Color::mFormat, &r, &g ,&b, &a);
	return b;
}

uint8_t Color::GetAlpha() const {
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
	SDL_GetRGBA(mColor, Color::mFormat, &r, &g ,&b, &a);
	return a;
}

Color Color::yellow() {
	return SDL_MapRGBA(Color::mFormat, 255, 255, 0, 0);
}

Color Color::Red() {
	return SDL_MapRGBA(Color::mFormat, 255, 0, 0, 0);
}

Color Color::Blue() {
	return SDL_MapRGBA(Color::mFormat, 0, 0, 255, 0);
}

Color Color::Green() {
	return SDL_MapRGBA(Color::mFormat, 0, 255, 0, 0);
}

Color Color::Black() {
	return SDL_MapRGBA(Color::mFormat, 0, 0, 0, 0);
}

Color Color::White() {
	return SDL_MapRGBA(Color::mFormat, 255, 255, 255, 0);
}

Color Color::AlphaBending(const Color &source, const Color &Destination) {

	Color OutColor;
	// source* src Alpha + dest * destAlpha
	float srcAlpha = float (source.GetAlpha())/255.0;
	float destAlpha = 1.0 - srcAlpha;

	OutColor.SetAlpha(255);
	OutColor.SetRed(float((source.GetRed()*srcAlpha) + (Destination.GetRed()*destAlpha)));
	OutColor.SetGreen(float((source.GetGreen()*srcAlpha) + (Destination.GetGreen()*destAlpha)));
	OutColor.SetBlue(float((source.GetBlue()*srcAlpha) + (Destination.GetBlue()*destAlpha)));

	return OutColor;
}

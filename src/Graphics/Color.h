/*
 * Color.h
 *
 *  Created on: Mar 28, 2020
 *      Author: sherif
 */

#ifndef GRAPHICS_COLOR_H_
#define GRAPHICS_COLOR_H_


#include <stdint.h>
struct SDL_PixelFormat;

class Color {
	uint32_t mColor;

public:
	static const SDL_PixelFormat * mFormat; //Forward declaration

	static void InitColorFormat(const SDL_PixelFormat * format);

	Color () : mColor(0) {}
	Color (uint32_t color) : mColor(color) {}
	Color (uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	inline bool operator==(const Color&c) const {return mColor ==c.mColor;}
	inline bool operator!=(const Color&c) const {return !(*this == c);}

	inline uint32_t GetPixelColor() const {return mColor;}

	void SetRGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

	void SetRed(uint8_t red);
	void SetGreen(uint8_t green);
	void SetBlue(uint8_t blue);
	void SetAlpha(uint8_t alpha);


	uint8_t GetRed() const;
	uint8_t GetGreen() const;
	uint8_t GetBlue() const;
	uint8_t GetAlpha() const;

	static Color yellow();
	static Color Red();
	static Color Blue();
	static Color Green();
	static Color Black();
	static Color White();
	static Color AlphaBending(const Color &source, const Color &Destination);
};

#endif /* GRAPHICS_COLOR_H_ */

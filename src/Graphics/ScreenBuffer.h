

#include "Color.h"
#include <SDL2/SDL.h>


class ScreenBuffer {
public:
	ScreenBuffer();
	ScreenBuffer (const ScreenBuffer &screenBuffer);
	~ScreenBuffer();
	void SetPixel(const Color& color, uint32_t x, uint32_t y);
	void Clear(const Color& c);

	void Init (uint32_t format, uint32_t w, uint32_t h);
	const ScreenBuffer& operator= (const ScreenBuffer &screenBuffer);
	SDL_Surface* GetSurface() {
		return mSurface;
	}

private:
	SDL_Surface *mSurface;
	uint32_t GetIndex(uint32_t r, uint32_t c) {
		return (mSurface->w * r) + c;
	}
};

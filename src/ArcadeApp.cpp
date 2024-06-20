//============================================================================
// Name        : ArcadeApp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//#include "Color.h"
//#include "Line.h"
//#include "Triangle.h"
//#include "AARectangle.h"
//#include "Circle.h"
//#include "Screen.h"
//#include <SDL2/SDL.h>

#include <iostream>
#include "App/App.h"
using namespace std;

// const int SCREEN_WIDTH = 224;
// const int SCREEN_HEIGHT = 288;
const int SCREEN_WIDTH = 512;
const int SCREEN_HEIGHT = 512;
const int Magnification = 1;
//void SetPixel(SDL_Surface *surface, uint32_t color, int x, int y);
//size_t GetIndex(SDL_Surface *surface, int r, int c);

int main(int argc, char* argv[]) {
//    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
//        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
//    }
//
//    SDL_Window *window = SDL_CreateWindow("Arcade",
//    		SDL_WINDOWPOS_CENTERED,
//			SDL_WINDOWPOS_CENTERED,
//			SCREEN_WIDTH,
//			SCREEN_HEIGHT, 0);
//
//    if(window == nullptr) {
//    	cout<<"we r foocked"<<endl;
//    }
//
//    SDL_Surface *image = SDL_GetWindowSurface(window);
//
//    SDL_PixelFormat *pixelformat = image->format;
//
//    cout<<"Pixel Format is "<<SDL_GetPixelFormatName(pixelformat->format)<<endl;
//
//    Color::InitColorFormat(pixelformat);
//    Color c(255,255,0,0);
//    cout<<"color = "<<c.GetPixelColor()<<endl;
//
//    ScreenBuffer mybuffer;
//    mybuffer.Init(pixelformat->format, SCREEN_WIDTH, SCREEN_HEIGHT);
//    mybuffer.SetPixel(c, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
//    SDL_BlitSurface(mybuffer.GetSurface(), 0, image, 0);
//
//    SDL_UpdateWindowSurface(window);

//	Screen myScreen;
//	Line myLine;
//	myLine.Setmp0(Vec2D(0,0));
//	myLine.Setmp1(Vec2D(SCREEN_WIDTH,SCREEN_HEIGHT));
//			//cout<<myLine.Getmp0().GetVec2Dy()<<endl;
//			//cout<<myLine.Getmp1().GetVec2Dy()<<endl;
//	myScreen.init(SCREEN_WIDTH, SCREEN_HEIGHT, 1);
			//myScreen.draw(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, Color::Red());
	//myScreen.draw(myLine, Color::Red());
	//myScreen.SwapScreen();


//	Triangle myTri(Vec2D(25,25),Vec2D(100,150),Vec2D(200,75));
//	myScreen.draw(myTri, Color::Red(), true, Color::Blue());
//	myScreen.SwapScreen();

//	Circle Circ(Vec2D(100.0,100.0), 50.0);
//	myScreen.draw(Circ, Color::Red(), true, Color::Blue());
//	myScreen.SwapScreen();

//	AARectangle rect(Vec2D(25.0,25.0), Vec2D(200.0,200.0));
//	myScreen.draw(rect, Color::Red(), true);
//	myScreen.SwapScreen();

//	Circle Circ(Vec2D(SCREEN_WIDTH/2+50,SCREEN_HEIGHT/2+50), 50.0);
//	AARectangle rect(Vec2D(SCREEN_WIDTH/2-25,SCREEN_HEIGHT/2-25), 50, 50);
//
//	myScreen.draw(rect, Color::Blue(), true, Color::Blue());
//	myScreen.draw(Circ, Color(0,255,0,150), true, Color(0,255,0,150));
//	myScreen.SwapScreen();
//
//    bool running = true;
//    SDL_Event event;
//    while(running) {
//    	while(SDL_PollEvent(&event)) {
//    		switch(event.type) {
//    			case SDL_QUIT:
//    				running = false;
//    				break;
//    		}
//    	}
//    }

//    SDL_DestroyWindow(window);
//    SDL_Quit();

	if (App::Singleton().Init(SCREEN_WIDTH, SCREEN_HEIGHT, Magnification))
		App::Singleton().Run();


	// find the first occurrence of the character after the input delimiter
//	string str = "shit this bullshit";
//	int dem = 0;
//	size_t i = str.find_first_of(" ", dem+17);
//
//	if (i == string::npos) {
//		cout<<"bullshit"<<endl;
//	}
//
//	cout<<i<<endl;


	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	return 0;
}

//void SetPixel(SDL_Surface *surface, uint32_t color, int x, int y) {
//
//	uint32_t *pixels = (uint32_t *)surface->pixels;
//	size_t index = GetIndex(surface, y, x);
//	pixels[index] = color;
//}
//
//size_t GetIndex(SDL_Surface *surface, int r, int c) {
//	return (surface->w * r) + c;
//
//}



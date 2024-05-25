/*
 * Screen.cpp
 *
 *  Created on: Jan 16, 2021
 *      Author: sherif
 */

#include "Screen.h"
#include <math.h>
#include <algorithm>
#include <iostream>
#include "Vec2D.h"

using namespace std;

Screen::Screen() : mwidth(0), mheight(0), window(nullptr), image(nullptr) {
	// TODO Auto-generated constructor stub

}

Screen::~Screen() {
	if (window) {
		SDL_DestroyWindow(window);
		window = nullptr;
	}
	SDL_Quit();
}

SDL_Window* Screen::init (uint32_t w, uint32_t h, uint32_t mag) {
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    }

	mwidth = w;
	mheight = h;

    window = SDL_CreateWindow("Arcade",
    		SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			mwidth*mag,
			mheight*mag, 0);

    if(window == nullptr) {
    	cout<< "couldn't create window"<< endl;
    }
    else {
    	image = SDL_GetWindowSurface(window);

		SDL_PixelFormat *pixelformat = image->format;

		//cout<<"Pixel Format is "<<SDL_GetPixelFormatName(pixelformat->format)<<endl;

		Color::InitColorFormat(pixelformat);

		mClearColor = Color::Black();

		mBackBuffer.Init(pixelformat->format, mwidth, mheight);

		ClearScreen();
    }
    return window;
}

void Screen::SwapScreen() {

	if (image) {
		ClearScreen();
		SDL_BlitSurface(mBackBuffer.GetSurface(), 0, image, 0);
		SDL_UpdateWindowSurface(window);
		mBackBuffer.Clear(mClearColor.GetPixelColor());
	}
}


void Screen::ClearScreen() {
	//mBackBuffer.Clear(Color::Black());
	SDL_FillRect(image, nullptr, mClearColor.GetPixelColor());
}

void Screen::draw(uint32_t x, uint32_t y, Color color) {
	mBackBuffer.SetPixel(color, x, y);
}

void Screen::draw(Line line, Color color) 
{
	int x0 = roundf(line.Getmp0().GetVec2Dx());
	int y0 = roundf(line.Getmp0().GetVec2Dy());
	int x1 = roundf(line.Getmp1().GetVec2Dx());
	int y1 = roundf(line.Getmp1().GetVec2Dy());

	int dx = x1 - x0;
	int dy = y1 - y0;	

	signed const char ix((dx>0) - (dx<0)); // 1 or -1
	signed const char iy((dy>0) - (dy<0));

	dx = abs(dx) * 2;
	dy = abs(dy) * 2;
	draw(x0, y0, color);

	if(dx >= dy) 
	{
		int d = dy - dx/2;
		while (x0 != x1) 
		{
			if (d >= 0) 
			{
				d -= dx;
				y0 += iy;
			}
			d += dy;
			x0 += ix;		
			draw(x0, y0, color);
		}
	}
	else 
	{
		int d = dx - dy/2;
		while (y0 != y1) 
		{
			if (d >=0) 
			{
				d -= dy;
				x0 += ix;
			}
			d += dx;
			y0 += iy;		
			draw(x0, y0, color);			
		}
	}
}

void Screen::draw(Triangle triangle, Color color, bool fillColor, Color colorFilling) 
{
	if (fillColor == true) {
		FillPoly(triangle.GetPoints(), colorFilling);
	}

	Line myLine;
	myLine.Setmp0(Vec2D(triangle.GetP0().GetVec2Dx(),triangle.GetP0().GetVec2Dy()));
	myLine.Setmp1(Vec2D(triangle.GetP1().GetVec2Dx(),triangle.GetP1().GetVec2Dy()));
	draw(myLine, color);
	myLine.Setmp0(Vec2D(triangle.GetP1().GetVec2Dx(),triangle.GetP1().GetVec2Dy()));
	myLine.Setmp1(Vec2D(triangle.GetP2().GetVec2Dx(),triangle.GetP2().GetVec2Dy()));
	draw(myLine, color);
	myLine.Setmp0(Vec2D(triangle.GetP2().GetVec2Dx(),triangle.GetP2().GetVec2Dy()));
	myLine.Setmp1(Vec2D(triangle.GetP0().GetVec2Dx(),triangle.GetP0().GetVec2Dy()));
	draw(myLine, color);
}

void Screen::draw(AARectangle rect, Color color, bool fillColor, Color colorFilling) 
{
	if (fillColor == true) {
		FillPoly(rect.GetPoints(), colorFilling);
	}

	vector<Vec2D> GetRectPoints = rect.GetPoints();
	Line myLine;
	myLine.Setmp0(Vec2D(GetRectPoints[0].GetVec2Dx(),GetRectPoints[0].GetVec2Dy()));
	myLine.Setmp1(Vec2D(GetRectPoints[1].GetVec2Dx(),GetRectPoints[1].GetVec2Dy()));
	draw(myLine, color);
	myLine.Setmp0(Vec2D(GetRectPoints[1].GetVec2Dx(),GetRectPoints[1].GetVec2Dy()));
	myLine.Setmp1(Vec2D(GetRectPoints[2].GetVec2Dx(),GetRectPoints[2].GetVec2Dy()));
	draw(myLine, color);
	myLine.Setmp0(Vec2D(GetRectPoints[2].GetVec2Dx(),GetRectPoints[2].GetVec2Dy()));
	myLine.Setmp1(Vec2D(GetRectPoints[3].GetVec2Dx(),GetRectPoints[3].GetVec2Dy()));
	draw(myLine, color);
	myLine.Setmp0(Vec2D(GetRectPoints[3].GetVec2Dx(),GetRectPoints[3].GetVec2Dy()));
	myLine.Setmp1(Vec2D(GetRectPoints[0].GetVec2Dx(),GetRectPoints[0].GetVec2Dy()));
	draw(myLine, color);
}

void Screen::draw(Circle circle, Color color, bool fillColor, Color colorFilling) 
{
	uint32_t x1 = 0;
	uint32_t y1 = 0;

	vector<Vec2D> circlePoints;

	float degree = 0;
	
	while (degree<360.0) 
	{
		x1 = circle.GetCenterPoint().GetVec2Dx() + (circle.GetRadius()*cos ( (degree * 3.14159) / 180.0 ));
		y1 = circle.GetCenterPoint().GetVec2Dy() + (circle.GetRadius()*sin ( (degree * 3.14159) / 180.0 ));
		circlePoints.push_back(Vec2D(x1,y1));
		draw(x1, y1, color);
		degree += 0.1;
	}

	// vector<Vec2D> circlePoints;
	// vector<Line> lines;
	// Line nextLineToDraw;
	// static unsigned int NUM_CIRCLE_SEGMENTS = 30;
	// float angle = (TWO_PI / (float)(NUM_CIRCLE_SEGMENTS));
	// Vec2D p0 = Vec2D(circle.GetCenterPoint().GetVec2Dx() + circle.GetRadius(), circle.GetCenterPoint().GetVec2Dy()); 
	// Vec2D p1 = p0;

	// for(unsigned int segment = 0; segment < NUM_CIRCLE_SEGMENTS; ++segment)
	// {
	// 	// rotate p1
	// 	p1.Rotate(angle, circle.GetCenterPoint());
	// 	nextLineToDraw.Setmp0(p0);
	// 	nextLineToDraw.Setmp1(p1);
	// 	lines.push_back(nextLineToDraw);
	// 	if(p1.GetVec2Dx() < 288 && p1.GetVec2Dy() < 288	)	
	// 	{
	// 		p0 = p1;
	// 	}
	// 	else break;
		
	// }

	if (true == fillColor) {
		FillPoly(circlePoints, colorFilling);
	}
	// for (const auto line : lines)
	// {
	// 	{		
	// 		draw(line, color);
	// 	}
	// }
}

void Screen::FillPoly(vector<Vec2D> points, Color mColor) {
	// get boundaries of the polygon (top y , bottom y, left x , right x)
	float top = points[0].GetVec2Dy();
	float bottom = points[0].GetVec2Dy();
	float left = points[0].GetVec2Dx();
	float right = points[0].GetVec2Dx();

	for(size_t i = 1; i < points.size(); i++) {
		if(points[i].GetVec2Dy() < top)
			top = points[i].GetVec2Dy();
		if(points[i].GetVec2Dy() > bottom)
			bottom = points[i].GetVec2Dy();
		if(points[i].GetVec2Dx() < left)
			left = points[i].GetVec2Dx();
		if(points[i].GetVec2Dx() > right)
			right = points[i].GetVec2Dx();
	}

	// get intersections of x with y on polygon
	for (int Pixely = top; Pixely < bottom; ++Pixely) {
		size_t j = points.size() - 1;
		vector<float> nodeVecx;
		for (size_t i = 0; i < points.size(); ++i) {
			float Pointiy = points[i].GetVec2Dy();
			float Pointjy = points[j].GetVec2Dy();

			if (((float)Pixely >= Pointiy && (float)Pixely < Pointjy) || ((float)Pixely >= Pointjy && (float)Pixely < Pointiy)) {
				float denom = Pointjy - Pointiy;
				if (IsEqual(denom,0)) {
					continue;
				}
				float x = points[i].GetVec2Dx() + (((Pixely - Pointiy)/denom) * (points[j].GetVec2Dx() - points[i].GetVec2Dx()));
				nodeVecx.push_back(x);
			}
			j = i;
		}

		std::sort(nodeVecx.begin(), nodeVecx.end(), std::less<>());

		// Rebound the x's to the x's of the polygon
		for (size_t k = 0; k < nodeVecx.size(); k+=2) {
			if (nodeVecx[k] > right) {
				break;
			}
			if (nodeVecx[k+1] > left) {
				if (nodeVecx[k] < left) {
					nodeVecx[k] = left;
				}
				if (nodeVecx[k+1] > right) {
					nodeVecx[k+1] = right;
				}
				// draw with x,y and color
				for (int dw = nodeVecx[k]; dw <= nodeVecx[k+1]; ++dw) {
					draw(dw, Pixely, mColor);
				}
			}
		}

	}
}



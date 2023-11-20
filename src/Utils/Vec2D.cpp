/*
 * Vec2D.cpp
 *
 *  Created on: Jan 16, 2021
 *      Author: sherif
 */

#include "Vec2D.h"

Vec2D Vec2D::operator* (const float f) const {
	return Vec2D(mpx*f, mpy*f);
}

//Vec2D Vec2D::operator= (const Vec2D &v)  {
//	return Vec2D(v.mpx, v.mpy);
//}
bool Vec2D::operator== (const Vec2D &v) const {
	if(fabsf(mpx-v.mpx) < EPSILON && fabsf(mpy-v.mpy) < EPSILON)
		return 1;
	else return 0;
}

Vec2D Vec2D::operator+ (const Vec2D &v) const {
	return Vec2D(mpx + v.mpx, mpy + v.mpy);
}

Vec2D Vec2D::operator- (const Vec2D &v) const {
	return Vec2D(mpx - v.mpx, mpy - v.mpy);
}

float Vec2D::mag() const {
	return sqrt(this->mag2());
}
float Vec2D::mag2() const {
	return mpx*mpx + mpy*mpy;
}

float Vec2D::Distance(const Vec2D &v) const {
	return (*this - v).mag();
}

Vec2D Vec2D::Zero() {
	return Vec2D(0,0);
}





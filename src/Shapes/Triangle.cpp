/*
 * Triangle.cpp
 *
 *  Created on: Feb 13, 2021
 *      Author: sherif
 */

#include <Triangle.h>

Vec2D Triangle::GetCenterPoint() const {
	return Vec2D((GetP0().GetVec2Dx()+ GetP1().GetVec2Dx()+ GetP2().GetVec2Dx())/3.0,
			(GetP0().GetVec2Dy()+ GetP1().GetVec2Dy()+ GetP2().GetVec2Dy())/3.0
	);
}

bool Triangle::ContainsPoint(const Vec2D& p) {
	float A1 = 0.0;
	float A2 = 0.0;
	float A3 = 0.0;
	A1 = Area(GetP0(), GetP1(), p);
	A2 = Area(GetP0(), p, GetP2());
	A3 = Area(p, GetP1(), GetP2());

	if ((A1 + A2 + A3) == Area(GetP0(), GetP1(), GetP2()))
		return true;
	else return false;
}

float Triangle::Area(const Vec2D& a, const Vec2D& b, const Vec2D& c) {
	return (0.5 *
			fabsf((GetP0().GetVec2Dx() * (GetP1().GetVec2Dy()- GetP2().GetVec2Dy()))

			+ (GetP1().GetVec2Dx() * (GetP2().GetVec2Dy()- GetP0().GetVec2Dy()))

			+ (GetP2().GetVec2Dx() * (GetP0().GetVec2Dy()- GetP1().GetVec2Dy()))
			));
}


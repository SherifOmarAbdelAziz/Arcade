/*
 * Circle.cpp
 *
 *  Created on: Feb 13, 2021
 *      Author: sherif
 */

#include <Circle.h>

bool Circle::ContainsPoint(const Vec2D& p) {
	return (
			GetCenterPoint().Distance(p) <
			radius
			);
}

bool Circle::intersects(const Circle &other) {
	return (
			GetCenterPoint().Distance(other.GetCenterPoint()) <
			(radius+ other.GetRadius())
			);
}


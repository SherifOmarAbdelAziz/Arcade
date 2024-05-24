/*
 * Line.cpp
 *
 *  Created on: Jan 16, 2021
 *      Author: sherif
 */

#include <Line.h>

Vec2D Line::ClosestPoint(const Vec2D &point, bool limitToSegment = false) const {
	
	Vec2D p02point = point - mp0;
	Vec2D p02p1 = mp1 - mp0;
	float distanceOnLine = p02point.Dot(p02p1);
	float p02p1Magnitude = p02p1.mag2();

	float distanceNorm = distanceOnLine/p02p1Magnitude; 
	if(limitToSegment)
	{
		distanceNorm = std::fmax(0, std::fmin(1.0f, distanceNorm));
	}	
	return (mp0 + (p02p1 * distanceNorm));
}


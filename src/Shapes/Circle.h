/*
 * Circle.h
 *
 *  Created on: Feb 13, 2021
 *      Author: sherif
 */

#ifndef SHAPES_CIRCLE_H_
#define SHAPES_CIRCLE_H_

#include "Vec2D.h"
#include "Shape.h"

class Circle : public Shape {
public:
	Circle() : Circle(Vec2D(0,0), 0.0) {}
	Circle(const Vec2D& center, float r) {
		mPoints.push_back(center);
		radius = r;
	}

	virtual Vec2D GetCenterPoint() const {
		return mPoints[0];
	}
	float GetRadius() const {
		return radius;
	}
	void SetRadius(const float& r) {
		radius = r;
	}
	void MoveTo(const Vec2D& position) {
		mPoints[0] = position;
	}

	bool ContainsPoint(const Vec2D& p);
	bool intersects(const Circle &other);

private:
	float radius;
};

#endif /* SHAPES_CIRCLE_H_ */

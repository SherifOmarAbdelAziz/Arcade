/*
 * Shape.h
 *
 *  Created on: Feb 13, 2021
 *      Author: sherif
 */

#ifndef SHAPES_SHAPE_H_
#define SHAPES_SHAPE_H_

#include <vector>
#include "Vec2D.h"
using namespace std;

class Shape {

public:
	virtual Vec2D GetCenterPoint() const = 0;
	virtual ~Shape() {}
	void MoveBy(const Vec2D &mypoint);
	virtual vector<Vec2D> GetPoints() {return mPoints;}
protected:
	vector<Vec2D> mPoints;

};

#endif /* SHAPES_SHAPE_H_ */

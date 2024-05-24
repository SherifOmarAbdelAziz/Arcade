/*
 * Triangle.h
 *
 *  Created on: Feb 13, 2021
 *      Author: sherif
 */

#ifndef SHAPES_TRIANGLE_H_
#define SHAPES_TRIANGLE_H_

#include "Vec2D.h"
#include "Shape.h"
#include <vector>
using namespace std;

class Triangle : public Shape {
public:
	Triangle(const Vec2D& P0, const Vec2D& P1, const Vec2D& P2) {
		mPoints.push_back(P0);
		mPoints.push_back(P1);
		mPoints.push_back(P2);
	}
	//~Triangle() {}
	void SetP0 (const Vec2D& P0) {mPoints[0] = P0;}
	void SetP1 (const Vec2D& P1) {mPoints[0] = P1;}
	void SetP2 (const Vec2D& P2) {mPoints[0] = P2;}
	Vec2D GetP0() const {return mPoints[0];}
	Vec2D GetP1() const {return mPoints[1];}
	Vec2D GetP2() const {return mPoints[2];}

	virtual Vec2D GetCenterPoint() const;
	bool ContainsPoint(const Vec2D& p);
	float Area(const Vec2D&, const Vec2D&, const Vec2D&);

	vector<Vec2D> GetPoints() {
		vector<Vec2D> Tri_points;
		Tri_points.push_back(mPoints[0]);
		Tri_points.push_back(mPoints[1]);
		Tri_points.push_back(mPoints[2]);
		return Tri_points;
	}

private:
	//float Area();
};

#endif /* SHAPES_TRIANGLE_H_ */

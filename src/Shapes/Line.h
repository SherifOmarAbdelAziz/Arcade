/*
 * Line.h
 *
 *  Created on: Jan 16, 2021
 *      Author: sherif
 */

#include "Vec2D.h"
#include <iostream>
using namespace std;

#ifndef SHAPES_LINE_H_
#define SHAPES_LINE_H_

class Line {
public:
	Line() : mp0(0,0), mp1(0,0) {}
//	Line(const Line &other) {
//		mp0 = other.mp0;
//		mp1 = other.mp1;
//		cout<<"leeeeeeeeeeeeeeeeeeeeeeeeh"<<endl;
//	}

	void Setmp0(const Vec2D &p0) { mp0.SetVec2Dx(p0); mp0.SetVec2Dy(p0);}
	void Setmp1(const Vec2D &p1) {mp1.SetVec2Dy(p1); mp1.SetVec2Dx(p1);
		//cout<<"here"<<mp1.GetVec2Dy()<<endl;
	}
	Vec2D Getmp0() const {return mp0;}
	Vec2D Getmp1() const {return mp1;}

	float minDistanceFrom(const Vec2D &v) {
		return mp0.Distance(ClosestPoint(v, true));
	}
	Vec2D ClosestPoint(const Vec2D &v, bool limitToSegment) const;

	float Length() {
		return mp0.Distance(mp1);
	}

	Vec2D MidPoint() {
		return Vec2D(((mp0.GetVec2Dx()+mp1.GetVec2Dx())/2.0),
				((mp1.GetVec2Dy()+mp0.GetVec2Dy())/2.0));
	}

	float Slope () {
		float dx = mp1.GetVec2Dx()-mp0.GetVec2Dx();

		if (fabsf(dx) < EPSILON)
			return 0;
		float dy = mp1.GetVec2Dy()-mp0.GetVec2Dy();
		return dy/dx;
	}

private:
	Vec2D mp0;
	Vec2D mp1;
};

#endif /* SHAPES_LINE_H_ */

/*
 * AARectangle.h
 *
 *  Created on: Feb 13, 2021
 *      Author: sherif
 */

#ifndef SHAPES_AARECTANGLE_H_
#define SHAPES_AARECTANGLE_H_


#include "Vec2D.h"
#include "Shape.h"

class AARectangle : public Shape {
public:
	AARectangle() : AARectangle (Vec2D(0,0), Vec2D(0,0)) { }
	AARectangle(const Vec2D& TopLeftPoint, const Vec2D& BottomRightPoint){
		mPoints.push_back(TopLeftPoint);
		mPoints.push_back(BottomRightPoint);
	}
	AARectangle(const Vec2D& TopLeftPoint, unsigned int width, unsigned int height) {
		mPoints.push_back(TopLeftPoint);
		mPoints.push_back(Vec2D(TopLeftPoint.GetVec2Dx()+width-1,
				TopLeftPoint.GetVec2Dy()+height-1));
	}
	//~AARectangle();

	const AARectangle& operator= (const AARectangle& Rect) {
		//cout<<"called"<<endl;
		setTopLeftPoint(Rect.GetTopLeftPoint());
		setBottomRightPoint(Rect.GetBottomRightPoint());
		return *this;
		//return AARectangle(Vec2D(Rect.GetTopLeftPoint().GetVec2Dx(), Rect.GetTopLeftPoint().GetVec2Dy()), Rect.GetWidth(), Rect.GetHeight());
	}


	float GetWidth() const {
		return mPoints[1].GetVec2Dx() - mPoints[0].GetVec2Dx() + 1;
	}
	float GetHeight() const {
		return mPoints[1].GetVec2Dy() - mPoints[0].GetVec2Dy() + 1;
	}

	void setTopLeftPoint(const Vec2D& p) {
		//mPoints[0] = p;
		mPoints[0].SetVec2Dx(p);
		mPoints[0].SetVec2Dy(p);
	}
	void setBottomRightPoint(const Vec2D& p) {
		mPoints[1].SetVec2Dx(p);
		mPoints[1].SetVec2Dy(p);
	}
	Vec2D GetTopLeftPoint() const {return mPoints[0];}
	Vec2D GetBottomRightPoint() const {return mPoints[1];}

	bool ContainsPoint(const Vec2D &p) const;
	void MoveTo(const Vec2D &p);
	bool intersects(const AARectangle& rect) const;
	virtual Vec2D GetCenterPoint() const;
	vector<Vec2D> GetPoints();
	AARectangle inset(const AARectangle& rect, const Vec2D& p);
};

#endif /* SHAPES_AARECTANGLE_H_ */

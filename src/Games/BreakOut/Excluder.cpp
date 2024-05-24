/*
 * Excluder.cpp
 *
 *  Created on: Jun 2, 2021
 *      Author: sherif
 */

#include <Excluder.h>

void Excluder::Init(const AARectangle& rect, bool mReverse) {
	//mRect = Rect;
	// mRect.setTopLeftPoint(Vec2D(Rect.GetTopLeftPoint().GetVec2Dx(), Rect.GetTopLeftPoint().GetVec2Dy()));
	mRect.setTopLeftPoint(rect.GetTopLeftPoint());
	mRect.setBottomRightPoint(rect.GetBottomRightPoint());
	//cout<<mRect.GetTopLeftPoint().GetVec2Dx()<<", "<<mRect.GetTopLeftPoint().GetVec2Dy()<<endl;
	mReverseNormals = mReverse;
	setupEdges();
}

bool Excluder::DetectCollision(const AARectangle& Rect, BoundaryEdge& edge) 
{
	bool retVal = false;
	if(mRect.intersects(Rect)) 
	{
		float ymin, ymax, xmin, xmax, xsize, ysize;
		ymin = (mRect.GetTopLeftPoint().GetVec2Dy() >= Rect.GetTopLeftPoint().GetVec2Dy())? mRect.GetTopLeftPoint().GetVec2Dy() : Rect.GetTopLeftPoint().GetVec2Dy();
		ymax = (mRect.GetBottomRightPoint().GetVec2Dy() <= Rect.GetBottomRightPoint().GetVec2Dy())? mRect.GetBottomRightPoint().GetVec2Dy() : Rect.GetBottomRightPoint().GetVec2Dy();

		xmin = (mRect.GetTopLeftPoint().GetVec2Dx() >= Rect.GetTopLeftPoint().GetVec2Dx())? mRect.GetTopLeftPoint().GetVec2Dx() : Rect.GetTopLeftPoint().GetVec2Dx();
		xmax = (mRect.GetBottomRightPoint().GetVec2Dx() <= Rect.GetBottomRightPoint().GetVec2Dx())? mRect.GetBottomRightPoint().GetVec2Dx() : Rect.GetBottomRightPoint().GetVec2Dx();

		xsize = xmax - xmin;
		ysize = ymax - ymin;

		if (ysize > xsize) 
		{
			if(mRect.GetCenterPoint().GetVec2Dx() >= Rect.GetCenterPoint().GetVec2Dx()) {
				edge = mEdge[LEFT_EDGE];
			}
			else {
				edge = mEdge[RIGHT_EDGE];
			}
		}

		else 
		{
			if(mRect.GetCenterPoint().GetVec2Dy() >= Rect.GetCenterPoint().GetVec2Dy()) {
				edge = mEdge[UPPER_EDGE];
			}
			else {
				edge = mEdge[BOTTOM_EDGE];
			}
		}
		retVal = true;
	}
	else
		retVal = false;

	return retVal;
}

Vec2D Excluder::GetCollisionOffset(const AARectangle& Rect) 
{
	BoundaryEdge myedge;
	Vec2D Offset;
	if (DetectCollision(Rect,myedge)) 
	{
		float ymin, ymax, xmin, xmax, xsize, ysize;
		ymin = (mRect.GetTopLeftPoint().GetVec2Dy() >= Rect.GetTopLeftPoint().GetVec2Dy())? mRect.GetTopLeftPoint().GetVec2Dy() : Rect.GetTopLeftPoint().GetVec2Dy();
		ymax = (mRect.GetBottomRightPoint().GetVec2Dy() <= Rect.GetBottomRightPoint().GetVec2Dy())? Rect.GetBottomRightPoint().GetVec2Dy() : mRect.GetBottomRightPoint().GetVec2Dy();

		xmin = (mRect.GetTopLeftPoint().GetVec2Dy() >= Rect.GetTopLeftPoint().GetVec2Dy())? mRect.GetTopLeftPoint().GetVec2Dy() : Rect.GetTopLeftPoint().GetVec2Dy();
		xmax = (mRect.GetBottomRightPoint().GetVec2Dy() <= Rect.GetBottomRightPoint().GetVec2Dy())? Rect.GetBottomRightPoint().GetVec2Dy() : mRect.GetBottomRightPoint().GetVec2Dy();

		xsize = xmax - xmin;
		ysize = ymax - ymin;

		if (!IsEqual(myedge.normal.GetVec2Dy(), 0)) 
		{
			Offset = myedge.normal * (ysize+1);
		}
		else 
		{
			Offset = myedge.normal  * (xsize+1);
		}
	}
	return Offset;
}

const AARectangle& Excluder::GetAARectangle () const {
	return mRect;
}

BoundaryEdge& Excluder::GetBoundaryEdge(const EdgeType& edgeType) {
	return mEdge[edgeType];
}

void Excluder::MoveBy (Vec2D& delta) {
	mRect.MoveBy(delta);
	setupEdges();
}

void Excluder::MoveTo (Vec2D& point) {
	mRect.MoveTo(point);
	setupEdges();
}

void Excluder::setupEdges() {
	Line mLine;
	// mLine.Setmp0(Vec2D(mRect.GetTopLeftPoint().GetVec2Dx(),mRect.GetTopLeftPoint().GetVec2Dy()));
	mLine.Setmp0(mRect.GetTopLeftPoint());
	mLine.Setmp1(Vec2D(mRect.GetTopLeftPoint().GetVec2Dx(),mRect.GetBottomRightPoint().GetVec2Dy()));
	mEdge[LEFT_EDGE].edge = mLine;
	mEdge[LEFT_EDGE].normal = LEFT_DIR;

	mLine.Setmp0(Vec2D(mRect.GetBottomRightPoint().GetVec2Dx(),mRect.GetTopLeftPoint().GetVec2Dy()));
	// mLine.Setmp1(Vec2D(mRect.GetBottomRightPoint().GetVec2Dx(),mRect.GetBottomRightPoint().GetVec2Dy()));
	mLine.Setmp1(mRect.GetBottomRightPoint());
	mEdge[RIGHT_EDGE].edge = mLine;
	mEdge[RIGHT_EDGE].normal = RIGHT_DIR;

	mLine.Setmp0(Vec2D(mRect.GetTopLeftPoint().GetVec2Dx(),mRect.GetBottomRightPoint().GetVec2Dy()));
	// mLine.Setmp1(Vec2D(mRect.GetBottomRightPoint().GetVec2Dx(),mRect.GetBottomRightPoint().GetVec2Dy()));
	mLine.Setmp1(mRect.GetBottomRightPoint());
	mEdge[BOTTOM_EDGE].edge = mLine;
	mEdge[BOTTOM_EDGE].normal = DOWN_DIR;

	// mLine.Setmp0(Vec2D(mRect.GetTopLeftPoint().GetVec2Dx(),mRect.GetTopLeftPoint().GetVec2Dy()));
	mLine.Setmp0(mRect.GetTopLeftPoint());
	mLine.Setmp1(Vec2D(mRect.GetBottomRightPoint().GetVec2Dx(),mRect.GetTopLeftPoint().GetVec2Dy()));
	mEdge[UPPER_EDGE].edge = mLine;
	mEdge[UPPER_EDGE].normal = UP_DIR;

	if (mReverseNormals) {
		for (auto& edge : mEdge)
			edge.normal = edge.normal * -1;
	}
}


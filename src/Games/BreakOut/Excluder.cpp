/*
 * Excluder.cpp
 *
 *  Created on: Jun 2, 2021
 *      Author: sherif
 */

#include "Excluder.h"

void Excluder::Init(const AARectangle& rect, bool mReverse) {
	//mRect = Rect;
	// mRect.setTopLeftPoint(Vec2D(Rect.GetTopLeftPoint().GetVec2Dx(), Rect.GetTopLeftPoint().GetVec2Dy()));
	mRect.setTopLeftPoint(rect.GetTopLeftPoint());
	mRect.setBottomRightPoint(rect.GetBottomRightPoint());
	//cout<<mRect.GetTopLeftPoint().GetVec2Dx()<<", "<<mRect.GetTopLeftPoint().GetVec2Dy()<<endl;
	mReverseNormals = mReverse;
	setupEdges();
}

bool Excluder::HasCollided(const AARectangle& Rect, BoundaryEdge& edge) const
{
	bool retVal = false;
	if(mRect.intersects(Rect)) 
	{
		float yMin = 0.0, yMax = 0.0, xMin = 0.0, xMax = 0.0, xSize = 0.0, ySize = 0.0;
		yMin = (mRect.GetTopLeftPoint().GetVec2Dy() >= Rect.GetTopLeftPoint().GetVec2Dy())? mRect.GetTopLeftPoint().GetVec2Dy() : Rect.GetTopLeftPoint().GetVec2Dy();
		yMax = (mRect.GetBottomRightPoint().GetVec2Dy() <= Rect.GetBottomRightPoint().GetVec2Dy())? mRect.GetBottomRightPoint().GetVec2Dy() : Rect.GetBottomRightPoint().GetVec2Dy();
		ySize = yMax - yMin;

		xMin = (mRect.GetTopLeftPoint().GetVec2Dx() >= Rect.GetTopLeftPoint().GetVec2Dx())? mRect.GetTopLeftPoint().GetVec2Dx() : Rect.GetTopLeftPoint().GetVec2Dx();
		xMax = (mRect.GetBottomRightPoint().GetVec2Dx() <= Rect.GetBottomRightPoint().GetVec2Dx())? mRect.GetBottomRightPoint().GetVec2Dx() : Rect.GetBottomRightPoint().GetVec2Dx();
		xSize = xMax - xMin;
		
		if (ySize >= xSize) 
		{
			if(mRect.GetCenterPoint().GetVec2Dx() > Rect.GetCenterPoint().GetVec2Dx()) 
			{
				edge = mEdge[LEFT_EDGE];
			}
			else 
			{
				edge = mEdge[RIGHT_EDGE];
			}
		}
		else 
		{
			if(mRect.GetCenterPoint().GetVec2Dy() >= Rect.GetCenterPoint().GetVec2Dy()) 
			{
				edge = mEdge[UPPER_EDGE];
			}
			else 
			{
				edge = mEdge[BOTTOM_EDGE];
			}
		}
		retVal = true;
	}
	else
	{
		retVal = false;
	}
	return retVal;
}

Vec2D Excluder::GetCollisionOffset(const AARectangle& Rect) const
{
	BoundaryEdge myedge;
	Vec2D Offset = Vec2D::Zero();
	if (HasCollided(Rect,myedge)) 
	{
		float yMin = 0.0, yMax = 0.0, xMin = 0.0, xMax = 0.0, xSize = 0.0, ySize = 0.0;
		yMin = (mRect.GetTopLeftPoint().GetVec2Dy() >= Rect.GetTopLeftPoint().GetVec2Dy())? mRect.GetTopLeftPoint().GetVec2Dy() : Rect.GetTopLeftPoint().GetVec2Dy();
		yMax = (mRect.GetBottomRightPoint().GetVec2Dy() <= Rect.GetBottomRightPoint().GetVec2Dy())? Rect.GetBottomRightPoint().GetVec2Dy() : mRect.GetBottomRightPoint().GetVec2Dy();

		xMin = (mRect.GetTopLeftPoint().GetVec2Dy() >= Rect.GetTopLeftPoint().GetVec2Dy())? mRect.GetTopLeftPoint().GetVec2Dy() : Rect.GetTopLeftPoint().GetVec2Dy();
		xMax = (mRect.GetBottomRightPoint().GetVec2Dy() <= Rect.GetBottomRightPoint().GetVec2Dy())? Rect.GetBottomRightPoint().GetVec2Dy() : mRect.GetBottomRightPoint().GetVec2Dy();

		xSize = xMax - xMin;
		ySize = yMax - yMin;

		if (!IsEqual(myedge.normal.GetVec2Dy(), 0)) 
		{
			Offset = myedge.normal * (ySize+1);
		}
		else 
		{
			Offset = myedge.normal  * (xSize+1);
		}
	}
	return Offset;
}

const AARectangle& Excluder::GetAARectangle() const 
{
	return mRect;
}

const BoundaryEdge& Excluder::GetBoundaryEdge(const EdgeType& edgeType) const 
{
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

	if (mReverseNormals) 
	{
		for (auto& edge : mEdge)
			edge.normal = edge.normal * -1;
	}
}


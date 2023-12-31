/*
 * Excluder.h
 *
 *  Created on: Jun 2, 2021
 *      Author: sherif
 */

#ifndef GAMES_BREAKOUT_EXCLUDER_H_
#define GAMES_BREAKOUT_EXCLUDER_H_

#include "AARectangle.h"
#include "BoundaryEdge.h"

class Excluder {
public:
	virtual ~Excluder() {}
	void Init(const AARectangle& Rect, bool mReverse = false);
	bool DetectCollision(const AARectangle& Rect, BoundaryEdge& edge);
	Vec2D GetCollisionOffset(const AARectangle& Rect);

	const AARectangle& GetAARectangle () const;
	BoundaryEdge& GetBoundaryEdge(const EdgeType& Edge);
	void MoveBy (Vec2D& delta);
	void MoveTo (Vec2D& point);

private:
	void setupEdges();
	AARectangle mRect;
	BoundaryEdge mEdge[NUM_EDGES];
	bool mReverseNormals;
};

#endif /* GAMES_BREAKOUT_EXCLUDER_H_ */

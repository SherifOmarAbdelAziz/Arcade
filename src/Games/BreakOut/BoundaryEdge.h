/*
 * BoundaryEdge.h
 *
 *  Created on: Jun 2, 2021
 *      Author: sherif
 */

#ifndef GAMES_BREAKOUT_BOUNDARYEDGE_H_
#define GAMES_BREAKOUT_BOUNDARYEDGE_H_


#include "Vec2D.h"
#include "Line.h"

enum EdgeType {
	BOTTOM_EDGE = 0,
	UPPER_EDGE,
	LEFT_EDGE,
	RIGHT_EDGE,
	NUM_EDGES
};

static Vec2D UP_DIR = Vec2D(0, -1);
static Vec2D DOWN_DIR = Vec2D(0, 1);
static Vec2D LEFT_DIR = Vec2D(-1, 0);
static Vec2D RIGHT_DIR = Vec2D(1, 0);

struct BoundaryEdge {
	Vec2D normal;
	Line Edge;
};


#endif /* GAMES_BREAKOUT_BOUNDARYEDGE_H_ */

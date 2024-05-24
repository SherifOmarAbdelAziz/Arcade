/*
 * LevelBoundary.cpp
 *
 *  Created on: May 18, 2024
 *      Author: sherif
 */


#include "LevelBoundary.h"
#include "Ball.h"

LevelBoundary::LevelBoundary(const AARectangle &boundary)
{
    mIncluder.Init(boundary);
}

bool LevelBoundary::HasCollided(const Ball& ball, BoundaryEdge& edge)
{
    bool retVal = false;
    for(uint8_t edge_index = 0; edge_index < NUM_EDGES; edge_index++)
    {
        BoundaryEdge boundary_edge = mIncluder.GetBoundaryEdge(static_cast<EdgeType>(edge_index));
        if(HasCollidedWithEdge(ball, boundary_edge))
        {
            edge = boundary_edge;
            retVal = true;
            // should we break here ?
            //break;
        }
    }
    return retVal;
}


bool LevelBoundary::HasCollidedWithEdge(const Ball& ball, const BoundaryEdge& edge) const
{
    return edge.edge.minDistanceFrom(ball.GetPosition()) <= ball.GetRadius();
}
/*
 * Shape.cpp
 *
 *  Created on: Feb 13, 2021
 *      Author: sherif
 */

#include <Shape.h>
#include<iostream>
using namespace std;

void Shape::MoveBy(const Vec2D &mypoint) {

//	for (auto i : mPoints) {
//		i.SetVec2Dx(i + mypoint) ;
//		i.SetVec2Dy(i + mypoint) ;
//	}

	for (uint32_t i = 0; i<mPoints.size(); i++) {
		mPoints[i] = mPoints[i] + mypoint;
		// cout<< mPoints[1].GetVec2Dx()<< " " << mPoints[1].GetVec2Dy()<<endl;
	}

	//cout<< mPoints[0].GetVec2Dx()<< " " << mPoints[0].GetVec2Dy() <<endl;
	//cout<< mPoints[1].GetVec2Dx()<< " " << mPoints[1].GetVec2Dy()<<endl;

	

	//for (auto it = mPoints.begin(); it != mPoints.end(); it++)
		//*it++;
}

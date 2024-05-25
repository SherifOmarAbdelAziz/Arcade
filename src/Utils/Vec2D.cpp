/*
 * Vec2D.cpp
 *
 *  Created on: Jan 16, 2021
 *      Author: sherif
 */

#include <assert.h>
#include <math.h>
#include "Vec2D.h"
#include <iostream>

Vec2D Vec2D::operator* (const float f) const {
	return Vec2D(mpx*f, mpy*f);
}

//Vec2D Vec2D::operator= (const Vec2D &v)  {
//	return Vec2D(v.mpx, v.mpy);
//}
bool Vec2D::operator== (const Vec2D &v) const {
	if(fabsf(mpx-v.mpx) < EPSILON && fabsf(mpy-v.mpy) < EPSILON)
		return 1;
	else return 0;
}

Vec2D Vec2D::operator+ (const Vec2D &v) const {
	return Vec2D(mpx + v.mpx, mpy + v.mpy);
}

Vec2D Vec2D::operator- (const Vec2D &v) const {
	return Vec2D(mpx - v.mpx, mpy - v.mpy);
}

Vec2D Vec2D::operator-= (const Vec2D &v)
{
	return (*this - v);
}

Vec2D Vec2D::operator/ (const float& scale) const
{
	assert(fabs(scale) > EPSILON);
	return Vec2D(mpx/scale, mpy/scale);
}

Vec2D Vec2D::operator/= (const float& scale)
{
	assert(fabs(scale) > EPSILON);
	*this = *this / scale;
	return *this / scale;
}

float Vec2D::Dot(const Vec2D& v) const
{
	float f = 0;
	f = mpx * v.mpx + mpy * v.mpy;
	return f;
}

float Vec2D::mag() const {
	return sqrt(this->mag2());
}
float Vec2D::mag2() const {
	return Dot(*this);
}

float Vec2D::Distance(const Vec2D &v) const {
	return (*this - v).mag();
}

Vec2D Vec2D::Zero() {
	return Vec2D(0,0);
}

Vec2D Vec2D::GetUnitVec() const
{
	Vec2D retVec = Zero();
	float magnitude = this->mag();
	if (magnitude > EPSILON)
	{
		retVec = (*this)/magnitude;
		 
	}
	return retVec;
}

Vec2D Vec2D::Normalize()
{
	float magnitude = this->mag();
	if (magnitude > EPSILON)
	{
		*this /= magnitude;
	}
	return *this;
}

Vec2D Vec2D::ProjectOnto(const Vec2D& vec2) const
{
	// ( V DOT U ) * U
	Vec2D unitVec = vec2.GetUnitVec();
	return unitVec * (this->Dot(unitVec));
}


// Angle = (vec1)/mag(vec1) . (vec2)/mag(vec2)
float Vec2D::AngleBetween(const Vec2D& vec) const
{
	return acosf((this->GetUnitVec()).Dot(vec.GetUnitVec()));
}

// r = v - 2 * (v . n) * n
Vec2D Vec2D::Reflect(const Vec2D& normal) const
{
	// Vec2D retVal_project = ProjectOnto(normal);
	// Vec2D mul = retVal_project*2;
	// Vec2D retVal = *this - mul;
	// return retVal;
	return *this - (ProjectOnto(normal) * 2.0f);
}


void Vec2D::Rotate(float angle, Vec2D PointToRotateAround)
{
	float cosine = cosf(angle);
	float sine = sinf(angle);

	// decrement vec2d by PointToRotateAround
	Vec2D thisVec = Vec2D(this->GetVec2Dx(), this->GetVec2Dy());
	thisVec -= PointToRotateAround;

	// compute sine and cos for x and y
	// x_rotated = x*cos(angle) - y*sin(angle)
	float x_rotated = thisVec.GetVec2Dx()*cosine - thisVec.GetVec2Dy()*sine;
	// y_rotated = x*-sin(angle) + y*cos(angle)
	float y_rotated = thisVec.GetVec2Dx()*sine + thisVec.GetVec2Dy()*cosine;
	
	Vec2D rotated_point = Vec2D(x_rotated, y_rotated);

	// increment vec2d by PointToRotateAround
	*this = rotated_point + PointToRotateAround;
}

Vec2D Vec2D::RotatationResult(float angle, Vec2D PointToRotateAround) const
{
	float cosine = cosf(angle);
	float sine = sinf(angle);
	
	// decrement vec2d by PointToRotateAround
	Vec2D thisVec = Vec2D(this->mpx, this->mpy);
	thisVec -= PointToRotateAround;

	// compute sine and cos for x and y
	// x_rotated = x*cos(angle) - y*sin(angle)
	float x_rotated = thisVec.GetVec2Dx()*cosine - thisVec.GetVec2Dy()*sine;
	// y_rotated = x*-sin(angle) + y*cos(angle)
	float y_rotated = thisVec.GetVec2Dx()*sine + thisVec.GetVec2Dy()*cosine;

	Vec2D rotated_point = Vec2D(x_rotated, y_rotated);

	// increment vec2d by PointToRotateAround
	return (rotated_point + PointToRotateAround);
}
/*
 * Vec2D.h
 *
 *  Created on: Jan 16, 2021
 *      Author: sherif
 */

#include "Utils.h"

#ifndef UTILS_VEC2D_H_
#define UTILS_VEC2D_H_

class Vec2D {
public:
	Vec2D() : mpx(0), mpy(0) {}
	Vec2D(const float &x, const float &y) : mpx(x), mpy(y) {}

	void SetVec2Dx(const Vec2D &p) {mpx = p.mpx;}
	void SetVec2Dy(const Vec2D &p) {mpy = p.mpy;}
	inline float GetVec2Dx() const {return mpx;}
	inline float GetVec2Dy() const {return mpy;}

	Vec2D scalar_multiply(const float &f) const {
		Vec2D v;
		v.mpx *= f;
		v.mpy *= f;
		return v;
	}

	float Dot(const Vec2D& v) const;

	Vec2D GetUnitVec() const;
	Vec2D Normalize();

	Vec2D ProjectOnto(const Vec2D& vec2) const;
	float AngleBetween(const Vec2D& vec) const;
	Vec2D Reflect(const Vec2D& nromal) const;
	void Rotate(float angle, Vec2D PointToRotateAround);
	Vec2D RotatationResult(float angle, Vec2D PointToRotateAround) const;

	Vec2D operator* (const float f) const;
	//Vec2D& operator= (const Vec2D &v);
	bool operator== (const Vec2D &v) const;

	Vec2D operator+ (const Vec2D &v) const;
	Vec2D operator- (const Vec2D &v) const;
	Vec2D operator-= (const Vec2D &v);

	Vec2D operator/ (const float& f) const;
	Vec2D operator/= (const float& f);

	float mag() const;
	float mag2() const;

	float Distance(const Vec2D &v) const;

	static Vec2D Zero();

private:
		float mpx;
		float mpy;
};

#endif /* UTILS_VEC2D_H_ */

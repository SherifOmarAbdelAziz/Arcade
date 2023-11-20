/*
 * Utils.cpp
 *
 *  Created on: Apr 3, 2021
 *      Author: sherif
 */


#include "Utils.h"

bool IsEqual(float one, float two) {
	if (fabsf(one-two) < EPSILON)
		return true;
	else return false;
}

float MilliSecondstoSeconds (uint32_t dt) {
	return float((float)dt/1000.0);
}

bool IsGreaterThanOrEqual (const float x, const float y) {
	if (x>=y) {
		return true;
	}
	else return false;
}

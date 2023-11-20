/*
 * Utils.h
 *
 *  Created on: Jan 16, 2021
 *      Author: sherif
 */

#include <cmath>
#include <stdint.h>

#ifndef UTILS_UTILS_H_
#define UTILS_UTILS_H_

#define EPSILON 0.001
bool IsEqual(float one, float two);
float MilliSecondstoSeconds (uint32_t dt);


bool IsGreaterThanOrEqual (const float x, const float y);

#endif /* UTILS_UTILS_H_ */

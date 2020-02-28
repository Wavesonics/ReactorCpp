//
// Created by Adam on 2/28/2020.
//

#include "Utils.h"

float randf(const float min, const float max)
{
	return min + (static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max-min))));
}

float randPercent()
{
	return randf(0.0f, 1.0f);
}

vec2f rand_vec2(const float start, const float range)
{
	return vec2f(randf(start, range), randf(start, range));
}

bool about_equal(float a, float b, float epsilon)
{
	// the machine epsilon has to be scaled to the magnitude of the values used
	// and multiplied by the desired precision in ULPs (units in the last place)
	return (a - b) <= epsilon;
}
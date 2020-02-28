//
// Created by Adam on 2/28/2020.
//

#ifndef REACTORCPPTEST_UTILS_H
#define REACTORCPPTEST_UTILS_H

#include "../math/vec2.h"

float randf(const float min, const float max);
float randPercent();
vec2f rand_vec2(const float start, const float range);

bool about_equal(float a, float b, float epsilon);

#endif //REACTORCPPTEST_UTILS_H

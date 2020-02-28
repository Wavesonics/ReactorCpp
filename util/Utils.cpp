//
// Created by Adam on 2/28/2020.
//

#include "Utils.h"

float randf(const float min, const float max) {
    return min + (static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/max)));
}

vec2f rand_vec2(const float start, const float range) {
    return vec2f(randf(start, range), randf(start, range));
}
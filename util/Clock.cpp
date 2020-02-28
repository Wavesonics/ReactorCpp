//
// Created by Adam on 2/26/2020.
//

#include "Clock.h"
#include <chrono>

using namespace std;

Clock::Clock() {
    lastTick = chrono::high_resolution_clock::now();
    delta = 0.0f;
}

void Clock::tick() {
    chrono::time_point curTick = chrono::high_resolution_clock::now();
    chrono::duration dur = curTick - lastTick;
    auto ms = chrono::duration_cast<chrono::milliseconds>(dur).count();
    lastTick = curTick;
    delta = (float) ms / 1000.0f;
}

float Clock::getDetla() {
    return delta;
}

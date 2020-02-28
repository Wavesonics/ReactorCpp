//
// Created by Adam on 2/27/2020.
//

#include "Timer.h"

#include <chrono>

using namespace std;

Timer::Timer() {
    startTime = chrono::high_resolution_clock::now();
}

void Timer::start() {
    startTime = chrono::high_resolution_clock::now();
}

long Timer::end() {
    auto endTime = chrono::high_resolution_clock::now();
    chrono::duration dur = endTime - startTime;
    auto ms = chrono::duration_cast<chrono::milliseconds>(dur).count();
    return ms;
}

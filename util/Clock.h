//
// Created by Adam on 2/26/2020.
//

#ifndef REACTORCPPTEST_CLOCK_H
#define REACTORCPPTEST_CLOCK_H

#include <chrono>


class Clock {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> lastTick;
    float delta;
public:
    Clock();
    void tick();
    float getDetla();
};


#endif //REACTORCPPTEST_CLOCK_H

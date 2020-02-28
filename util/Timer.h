//
// Created by Adam on 2/27/2020.
//

#ifndef REACTORCPPTEST_TIMER_H
#define REACTORCPPTEST_TIMER_H

#include <chrono>


class Timer
{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
public:
	Timer();

	void start();

	long end();
};


#endif //REACTORCPPTEST_TIMER_H

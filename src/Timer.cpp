#include <chrono> //C++11

#include <iomanip>
#include <locale>
#include <string>
#include <sstream>
#include <iostream>
#include "Timer.h"

using namespace std;
using HRClock = std::chrono::high_resolution_clock;

Timer::Timer():m_startTime(HRClock::now())
{
	
}

Timer::~Timer()
{
	HRClock::time_point end_time = HRClock::now();
	std::chrono::nanoseconds time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - m_startTime);
	std::stringstream ss;
	ss.imbue(std::locale(""));
	ss << std::fixed << time_span.count();
	cout << "\nTime Duration: " << ss.str() << " nanoseconds";
}

#pragma once

#include <chrono> //C++11
#include <iomanip>
#include <locale>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using HRClock = std::chrono::high_resolution_clock;

class Timer
{
public:
	Timer();
	~Timer();

private:
	HRClock::time_point m_startTime;
};


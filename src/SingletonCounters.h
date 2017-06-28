#pragma once

#include <iostream>
using namespace std;

class SingletonCounters
{
public:
	void resetCounters();
	void incrementComparisons();
	void incrementSwaps();
	void incrementAssignments();
	int getComparisons();
	int getSwaps();
	int getAssignments();
	static SingletonCounters& get();

private:
	int m_comparisons;
	int m_swaps;
	int m_assignments;

};

#include <iostream>
#include "SingletonCounters.h";

using namespace std;

SingletonCounters::SingletonCounters(int myid)
{
	id = myid;
};

SingletonCounters* SingletonCounters::get()
{
	static SingletonCounters* ctr = new SingletonCounters(rand() + 1);
	return ctr;
}

void SingletonCounters::resetCounters()
{
	m_comparisons = 0;
	m_swaps = 0;
	m_assignments = 0;
}

void SingletonCounters::incrementComparisons()
{
	m_comparisons++;
}

void SingletonCounters::incrementSwaps()
{
	m_swaps++;
}

void SingletonCounters::incrementAssignments()
{
	m_assignments++;
}

int SingletonCounters::getComparisons()
{
	return m_comparisons;
}

int SingletonCounters::getSwaps()
{
	return m_swaps;
}

int SingletonCounters::getAssignments()
{
	return m_assignments;
}

	
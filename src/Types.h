#pragma once

#include <iostream> 
#include <string> 

using namespace std;

typedef enum
{
	BubbleSorting = 1,
	SelectionSorting = 2,
	InsertionSorting = 3
} Algos;

typedef enum
{
	Sorted,
	ReverseSorted,
	AlmostSorted,
	Random

} SampleType;

typedef struct
{
	SampleType Type;
	int Assignments;
	int Comparison;
	int Swaps;
} ExecutionStat;

typedef struct
{
	std::string Name;
	int SampleSize;
	ExecutionStat Stats[4];
} Result;

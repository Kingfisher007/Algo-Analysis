#include <iostream>
#include "Timer.h"
#include "Object.h"
#include "Bubblesort.h"

using namespace std;

void BubbleSort::bubbleSortInPlace1(Object obj[], int size)
{
	cout << endl << "bubbleSortInPlace1:";
	Timer t;
	for (int i = 0; i < size; i++)
	{
		bool nothingSwappedInLastIteration = true;
		for (int j = 1; j < size - i; j++)
		{
			if (obj[j - 1] > obj[j])
			{
				obj[j - 1].swap(obj[j]);
				nothingSwappedInLastIteration = false;
			}
		}
		if (nothingSwappedInLastIteration)
			break;
	}
}

void BubbleSort::bubbleSortInPlace2(Object obj[], int size)
{
	cout << endl << "bubbleSortInPlace2:";
	Timer t;
	int newSize = size;
	while (newSize > 0)
	{
		int sizeAfterThisIteration = 0;
		for (int j = 1; j < newSize; j++)
		{
			if (obj[j - 1] > obj[j])
			{
				obj[j - 1].swap(obj[j]);
				sizeAfterThisIteration = j;
			}
		}
		newSize = sizeAfterThisIteration;
	}
}

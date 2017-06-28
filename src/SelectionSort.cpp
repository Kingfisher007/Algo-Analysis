#include <iostream>
#include "Timer.h"
#include "Object.h"
#include "SelectionSort.h"

using namespace std;


void SelectionSort::SelectionSortInPlace(Object obj[], int size)
{
	cout << endl << "SelectionSortInPlace:";
	Timer t;
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (obj[i] > obj[j])
				obj[i].swap(obj[j]);
		}
	}
}
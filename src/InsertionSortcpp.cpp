#include <iostream>
#include "Timer.h"
#include "Object.h"
#include "InsertionSort.h"

using namespace std;


void InsertionSort::InsertionSortInPlace(Object obj[], int size)
{
	cout << endl << "SelectionSortInPlace:";
	
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (obj[i] > obj[j])
				obj[i].swap(obj[j]);
		}
	}
}
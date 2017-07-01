#include <iostream>
#include "Timer.h"
#include "Types.h"
#include "Object.h"
#include "CSVWriter.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h";
#include "SingletonCounters.h"
#include "ConsoleUI.h"

using namespace std;

typedef void(*sortFun)(Object obj[], int size);

void Execute(sortFun fun, std::string name);
ExecutionStat Run(SampleType type, sortFun fun, int size);
void GenerateSortedData(Object obj[],  int size);
void GenerateReverseSortedData(Object obj[], int size);
void GenerateAlmostSortedData(Object obj[], int size);
void GenerateRandomData(Object obj[], int size);

int main()
{
	int option = 0;
	int size = 0;

	ConsoleUI::DisplayHeader();
	
	do
	{
		ConsoleUI::DisplayMenu();
		option = ConsoleUI::GetSelection();

		switch (option)
		{
			case 1:
				Execute(&(BubbleSort::bubbleSortInPlace1), "Bubble sort");
				break;
			
			case 2:
				Execute(&(SelectionSort::SelectionSortInPlace), "Selection sort");
				break;
			
			case 3:
				Execute(&(InsertionSort::InsertionSortInPlace), "Insertion sort");
				break;

			default:
				cout << "Invalid option. Please try again." << endl;
		};
	} while (option != 9);

	cout << "Good bye!";

	return 0;
};

void Execute(sortFun fun, std::string name)
{
	int size = ConsoleUI::GetOptions();

	ExecutionStat stats[4];
	Result result;

	result.Name = name;
	result.SampleSize = size;

	result.Stats[0] = Run(SampleType::Sorted, fun, size);
	result.Stats[1] = Run(SampleType::ReverseSorted, fun, size);
	result.Stats[2] = Run(SampleType::AlmostSorted, fun, size);
	result.Stats[3] = Run(SampleType::Random, fun, size);

	ConsoleUI::DisplayResult(result);
};

ExecutionStat Run(SampleType type, sortFun fun, int size)
{
	Object *data = new Object[size];
	
	switch (type)
	{
		case SampleType::Sorted :
			GenerateSortedData(data, size);
		break;

		case SampleType::ReverseSorted:
			GenerateReverseSortedData(data, size);
			break;

		case SampleType::AlmostSorted:
			GenerateAlmostSortedData(data, size);
			break;

		case SampleType::Random:
			GenerateRandomData(data, size);
			break;
	};

	SingletonCounters* SCounter = SingletonCounters::get();
	SCounter->resetCounters();
	
	fun(data, size);

	ExecutionStat stat;
	stat.Type = type;
	stat.Assignments = SCounter->getAssignments();
	stat.Comparison = SCounter->getComparisons();
	stat.Swaps = SCounter->getSwaps();

	delete[] data;

	return stat;
};

void GenerateSortedData(Object *data, int size)
{
	for (int counter = 0; counter < size; counter++)
	{
		data[counter] = counter;
	};
};

void GenerateReverseSortedData(Object* obj, int size)
{
	for (int counter = size - 1; counter >= 0; counter--)
	{
		obj[size - counter - 1] = counter;
	};
};

void GenerateAlmostSortedData(Object* obj, int size)
{
	for (int counter = 0; counter < size; counter++)
	{
		obj[counter] = counter;
	};
	int temp;
	for (int counter = 5; counter < size; counter+=5)
	{
		temp = obj[counter];
		obj[counter] = obj[counter - 1];
		obj[counter - 1] = temp;
	};
};

void GenerateRandomData(Object* obj, int size)
{
	for (int counter = 0; counter < size; counter++)
	{
		obj[counter] = rand() % size + 1;
	};
};

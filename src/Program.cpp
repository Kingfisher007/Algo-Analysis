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
ExecutionStat Run(SampleType type, sortFun fun, Object data[], int size, SingletonCounters SCounter);
void GenerateSortedData(Object obj[], int size);
void GenerateReverseSortedData(Object obj[], int size);
void GenerateAlmostSortedData(Object obj[], int size);
void GenerateRandomData(Object obj[], int size);

static void Main(char* args)
{
	int option = 0;
	int size = 0;
	BubbleSort bs;
	SelectionSort ss;
	InsertionSort as;

	ConsoleUI::DisplayHeader();
	
	do
	{
		ConsoleUI::DisplayMenu();
		option = ConsoleUI::GetSelection();

		switch (option)
		{
			case 1:
				Execute(bs.bubbleSortInPlace1, "Bubble sort");
				break;
			
			case 2:
				Execute(ss.SelectionSortInPlace, "Selection sort");
				break;
			
			case 3:
				Execute(as.InsertionSortInPlace, "Insertion sort");
				break;

			default:
				cout << "Invalid option. Please try again." << endl;
		};
	} while (option != 9);

	cout << "Good bye!";
};

void Execute(sortFun fun, std::string name)
{
	int size = ConsoleUI::GetOptions();

	SingletonCounters SCounter = SingletonCounters::get();
	ExecutionStat stats[4];
	Object *data = new Object[size];
	Result result;

	result.Name = name;
	result.SampleSize = size;

	result.Stats[0] = Run(SampleType::Sorted, fun, data, size, SCounter);
	result.Stats[1] = Run(SampleType::ReverseSorted, fun, data, size, SCounter);
	result.Stats[2] = Run(SampleType::AlmostSorted, fun, data, size, SCounter);
	result.Stats[3] = Run(SampleType::Random, fun, data, size, SCounter);

	ConsoleUI::DisplayResult(result);

	delete(data);
};

ExecutionStat Run(SampleType type, sortFun fun, Object data[], int size, SingletonCounters SCounter)
{
	SCounter.resetCounters();
	
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
	
	fun(data, size);

	ExecutionStat stat;
	stat.Type = type;
	stat.Assignments = SCounter.getAssignments();
	stat.Comparison = SCounter.getComparisons();
	stat.Swaps = SCounter.getSwaps();

	return stat;
};

void GenerateSortedData(Object obj[], int size)
{
	for (int counter = 0; counter < size; counter++)
	{
		obj[counter] = counter;
	};
};

void GenerateReverseSortedData(Object obj[], int size)
{
	for (int counter = size; counter > 0; counter--)
	{
		obj[counter] = counter;
	};
};

void GenerateAlmostSortedData(Object obj[], int size)
{
	for (int counter = 0; counter < size; counter++)
	{
		obj[counter] = counter;
	};
	int temp;
	for (int counter = 5; counter < size; counter+5)
	{
		temp = obj[counter];
		obj[counter] = obj[counter - 1];
		obj[counter - 1] = temp;
	};
};

void GenerateRandomData(Object obj[], int size)
{
	for (int counter = 0; counter < size; counter++)
	{
		obj[counter] = rand() % size + 1;
	};
};

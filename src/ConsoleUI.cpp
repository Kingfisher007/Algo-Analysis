#include <iostream>
#include <iomanip>
#include "ConsoleUI.h"
#include "Types.h"

using namespace std;

void ConsoleUI::DisplayHeader()
{
	cout << "****************************************************************" << endl;
	cout << "                     Analysis of algorithms                     " << endl;
	cout << "****************************************************************" << endl;
	cout << endl;

};

void ConsoleUI::DisplayMenu()
{
	cout << "Select algorithm -" << endl;
	cout << Algos::BubbleSorting << ". Bubble sort" << endl;
	cout << Algos::SelectionSorting << ". Selection sort" << endl;
	cout << Algos::InsertionSorting << ". Insertion sort" << endl;
	cout << "9. Exit" << endl;
	cout << endl;
};

int ConsoleUI::GetSelection()
{
	int option = 0;
	cout << "Enter your option - ";
	cin >> option;
	return option;
};

int ConsoleUI::GetOptions()
{
	int size = 0;
	do
	{
		cout << "please provide data size : ";
		cin >> size;
	} while (size <= 0);

	return size;
};

void ConsoleUI::DisplayResult(Result result)
{
	std::cout << "************************************** Result ***************************************" << std::endl;
	std::cout << " Algorithm : " << result.Name << std::endl;
	std::cout << " Size : " << result.SampleSize << std::endl;
	std::cout << "--------------------------------------------------------------------------------------" << std::endl;
	std::cout << "| Input Type           |" << " Assignments   |" << " Comparisons    |" << " Swaps    |" << std::endl;
	std::cout << "--------------------------------------------------------------------------------------" << std::endl;
	ExecutionStat stat;
	for (int counter = 0; counter < 4; counter++)
	{
		stat = result.Stats[counter];
		std::cout << "|";
		std::cout << std::setw(20) << std::left << GetSampleName(stat.Type) << " |";
		std::cout << std::setw(15) << std::right << stat.Assignments << " |";
		std::cout << std::setw(15) << std::right << stat.Comparison << " |";
		std::cout << std::setw(8) << std::right << stat.Swaps << " |";
		std::cout << std::endl;
	};
	std::cout << "--------------------------------------------------------------------------------------" << std::endl;
	std::cout << " Press any key to continue..." << std::endl;
	std::cin;
};

std::string ConsoleUI::GetSampleName(SampleType type)
{
	std::string name = "";
	switch (type)
	{
	case SampleType::Sorted:
		name = "Sorted";
		break;

	case SampleType::ReverseSorted:
		name = "Reverse Sorted";
		break;

	case SampleType::AlmostSorted:
		name = "Almost Sorted";
		break;

	case SampleType::Random:
		name = "Random";
		break;
	};
	return name;
};
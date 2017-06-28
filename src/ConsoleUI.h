#pragma once

#include <iostream>
#include "Types.h"

using namespace std;

class ConsoleUI
{
public:
	static void DisplayHeader();
	static void DisplayMenu();
	static int GetSelection();
	static int GetOptions();
	static void DisplayResult(Result result);

private:
	static std::string GetSampleName(SampleType type);
};

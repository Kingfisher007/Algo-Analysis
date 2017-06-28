#pragma once

#include <fstream>
#include <locale>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class CSVWriter
{
public:
	CSVWriter(std::string filename, bool newFile = false);
	~CSVWriter();
	void write(std::string text);

private:
	ofstream m_file;
};

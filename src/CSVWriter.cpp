#include <fstream>
#include <locale>
#include <string>
#include <sstream>
#include <iostream>
#include "CSVWriter.h"

using namespace std;

CSVWriter::CSVWriter(std::string filename, bool newFile = false)
{
	int mode = ios::app;
	if (newFile)
		mode = ios::trunc;
	try
	{
		m_file.open(filename, mode);
	}
	catch (std::ofstream::failure &writeErr)
	{
		cout << "\nERROR: Can not open file: " << filename << endl;
	}
	catch (...)
	{
		cout << "\nUNKNOWN ERROR while opening file: " << filename << endl;
	}
}

CSVWriter::~CSVWriter()
{
	if (m_file.is_open())
		m_file.close();
}

void CSVWriter::write(std::string text)
{
	if (m_file.is_open())
		m_file.write(text.c_str(), text.length());
}

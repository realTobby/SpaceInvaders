
#include "logging.hpp"
#include <iostream>
#include <fstream>

using namespace std;

Logging::Logging(string lfp)
{
	logFilePath = lfp;
}

string Logging::ConvertEnumToString(Logging::LogLevel type)
{
	switch(type)
	{
		case Logging::Information:
			return "Information";
		case Logging::Warning:
			return "Warning";
		case Logging::Error:
			return "Error";
	}
	return "undefined";
}

void Logging::Log(Logging::LogLevel type, string message)
{
	// Create and open a text file
	ofstream LogFile;
	LogFile.open(logFilePath, std::ios_base::app);
	// Write to the file
	LogFile << "[" << ConvertEnumToString(type) << "] " << message << endl;

	// Close the file
	LogFile.close();
}
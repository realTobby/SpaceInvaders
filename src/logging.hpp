// logging.hpp
#include <string>

#ifndef Logging_h
#define Logging_h

using namespace std;

class Logging
{
	public:
		enum LogLevel {Information, Warning, Error};

	private:
		string logFilePath;
		string ConvertEnumToString(LogLevel type);

	public:
		
		Logging(string lfp);
		void Log(LogLevel type, string Message);
};
#endif
#include "Logger.h"
#include <iostream>

Logger::~Logger()
{
	std::cout << _buffer.str() << std::endl;
}

bool Logger::loggingEnabled()
{
	return true;
}

#include "Logger.h"
#include <iostream>

namespace
{
	LoggerWriter* loggerWriter = NULL;
}

LoggerWriter::~LoggerWriter()
{

}

void Logger::setWriter(LoggerWriter& writer)
{
	loggerWriter = &writer;
}

Logger::~Logger()
{
	if (loggerWriter)
		loggerWriter->write(_buffer.str());
}

bool Logger::loggingEnabled()
{
	return true;
}

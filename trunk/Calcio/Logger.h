#ifndef LOGGER_H
#define LOGGER_H

#include <sstream>

class Logger 
{
public:
	~Logger();
	
	template <typename T>
	Logger& operator << (const T& t)
	{
		_buffer << t;
		return *this;
	}

	static bool loggingEnabled();

private:
	std::ostringstream _buffer;
};

#define LOG_STD if (!Logger::loggingEnabled()); else Logger()

#endif

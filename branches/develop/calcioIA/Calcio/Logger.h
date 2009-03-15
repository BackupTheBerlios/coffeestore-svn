#ifndef LOGGER_H
#define LOGGER_H

#include <sstream>

class LoggerWriter
{
public:
	virtual ~LoggerWriter();
	virtual void write(const std::string line) = 0;
};

class Logger 
{
public:
	~Logger();
	
	static void setWriter(LoggerWriter& writer);

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
#define LOG_ELEM(name, value) #name << " [" << value << "] "


#endif

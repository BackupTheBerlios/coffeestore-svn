#ifndef GLUT_LOGGER_WRITER_H
#define GLUT_LOGGER_WRITER_H

#include <Logger.h>
#include <vector>

class Application;

class GlutLoggerWriter : public LoggerWriter
{
public:
	void flush(const Application& application);
	virtual void write(const std::string line);
private:
	std::vector<std::string> _lines;
};

#endif

#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include "GlutLoggerWriter.h"

class Point;

class Application
{
public:
	Application(int width, int height);
	virtual ~Application();

	void initialize(int argc, char** argv);

	virtual void display() = 0;
	virtual void update() = 0;
	virtual void keyboard(unsigned char key) = 0;

	virtual std::string title() const;

	int width() const;
	int height() const;

	void writeString(const Point& position, const std::string& str) const;

private:
	int _width;
	int _height;
	GlutLoggerWriter _loggerWriter;

	static void _idle();
	static void _display();
	static void _keyboard(unsigned char key, int x, int y);

	static Application* _instance;
};

#endif

#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include "GlutLoggerWriter.h"

class Point;

class Application
{
public:
	enum SpecialKey
	{
		SpecialKey_None,
		SpecialKey_Up,
		SpecialKey_Down,
		SpecialKey_Left,
		SpecialKey_Right,
	};

	Application(int width, int height);
	virtual ~Application();

	void initialize(int argc, char** argv);

	virtual void display() = 0;
	virtual void update() = 0;
	virtual void keyboard(unsigned char key) = 0;

	virtual std::string title() const;

	virtual void specialKeyUp(SpecialKey specialKey);
	virtual void specialKeyDown(SpecialKey specialKey);

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
	static void _special(int key, int x, int y);
	static void _specialUp(int key, int x, int y);

	static Application* _instance;
};

#endif

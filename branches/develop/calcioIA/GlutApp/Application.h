#ifndef APPLICATION_H
#define APPLICATION_H

class Application
{
public:
	Application(int width, int height);
	virtual ~Application();

	void initialize(int argc, char** argv);

	virtual void display() = 0;
	virtual void update() = 0;
	virtual void keyboard(unsigned char key) = 0;

	virtual const char* title() const;

	int width() const;
	int height() const;

private:
	int _width;
	int _height;

	static void _idle();
	static void _display();
	static void _keyboard(unsigned char key, int x, int y);

	static Application* _instance;
};

#endif

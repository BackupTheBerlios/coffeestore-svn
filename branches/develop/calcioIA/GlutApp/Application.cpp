#include "Application.h"
#include "GlutLoggerWriter.h"
#include <Point.h>
#include <cstdlib>
#include <cassert>
#include <GL/glut.h>

Application* Application::_instance = NULL;

Application::Application(int width, int height)
	:	_width(width), _height(height)	
{
	_instance = this;

	Logger::setWriter(_loggerWriter);
}

Application::~Application()
{

}

void Application::initialize(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(_width, _height);
	glutCreateWindow(title().c_str());
	glClearColor(0.0f, 0.7f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glutKeyboardFunc(_keyboard);
	glutSpecialFunc(_special);
	glutSpecialUpFunc(_specialUp);
	glutIdleFunc(_idle);
	glutDisplayFunc(_display);
	glutMainLoop();
}

void Application::specialKeyUp(SpecialKey specialKey)
{

}

void Application::specialKeyDown(SpecialKey specialKey)
{

}

std::string Application::title() const
{
	return "Application";
}

int Application::width() const
{
	return _width;
}

int Application::height() const
{
	return _height;
}

void Application::_idle()
{
	glutPostRedisplay();
}

void Application::_display()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-110.0f,110,-110.0f,110.0f);

	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	_instance->update();
	_instance->display();

	_instance->_loggerWriter.flush(*_instance);

	assert(glGetError() == GL_NO_ERROR);

	glutSwapBuffers();
	glFlush();
}

void Application::_keyboard(unsigned char key, int x, int y)
{
	_instance->keyboard(key);
}

void Application::_special(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		_instance->specialKeyDown(SpecialKey_Left);
		break;
	case GLUT_KEY_RIGHT:
		_instance->specialKeyDown(SpecialKey_Right);
		break;
	case GLUT_KEY_DOWN:
		_instance->specialKeyDown(SpecialKey_Down);
		break;
	case GLUT_KEY_UP:
		_instance->specialKeyDown(SpecialKey_Up);
		break;
	default:
		break;
	}
}

void Application::_specialUp(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		_instance->specialKeyUp(SpecialKey_Left);
		break;
	case GLUT_KEY_RIGHT:
		_instance->specialKeyUp(SpecialKey_Right);
		break;
	case GLUT_KEY_DOWN:
		_instance->specialKeyUp(SpecialKey_Down);
		break;
	case GLUT_KEY_UP:
		_instance->specialKeyUp(SpecialKey_Up);
		break;
	default:
		break;
	}
}

void Application::writeString(const Point& position, const std::string& str) const
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, _width, 0, _height);

	void* font = GLUT_BITMAP_HELVETICA_12;
	float x = position.x();
	glPushAttrib(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		glRasterPos3f(x, _height - position.y(), 1.0f);
		glutBitmapCharacter(font, *it);
		x += glutBitmapWidth(font, *it);
	}
	glPopAttrib();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

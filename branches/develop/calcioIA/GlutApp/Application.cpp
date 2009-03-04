#include "Application.h"
#include <cstdlib>
#include <cassert>
#include <GL/glut.h>

Application* Application::_instance = NULL;

Application::Application(int width, int height)
	:	_width(width), _height(height)	
{
	_instance = this;
}

Application::~Application()
{

}

void Application::initialize(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(_width, _height);
	glutCreateWindow(title());
	glClearColor(0.0f, 0.7f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glutKeyboardFunc(_keyboard);
	glutIdleFunc(_idle);
	glutDisplayFunc(_display);
	glutMainLoop();
}

const char* Application::title() const
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

	assert(glGetError() == GL_NO_ERROR);

	glutSwapBuffers();
	glFlush();
}

void Application::_keyboard(unsigned char key, int x, int y)
{
	_instance->keyboard(key);
}

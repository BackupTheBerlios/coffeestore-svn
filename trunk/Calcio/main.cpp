#include <cstdlib>
#include <GL/glut.h>
#include "Field.h"
#include "Ball.h"
#include "Team.h"
#include "GLDraw.h"


Team t1(Team::Color_BLUE);
Team t2(Team::Color_RED);
GLDraw draw;

void Init(void)
{
	glClearColor(0.0,.7,0.0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_DEPTH_TEST);;
	glEnable(GL_CULL_FACE);
}

void display()
{
	GLenum er = 0;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-110.0f,110,-110.0f,110.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);

	Field field;
	draw.draw(field);

	draw.draw(Ball(Point(45,0)));

	t1.run();
	t2.run();
	draw.draw(t1);
	draw.draw(t2);

	glutSwapBuffers();
	glFlush();
}

void ViewMouse(int button, int state, int x, int y)
{

}

void ViewMouseMotion(int x, int y)
{
}

void idle()
{
	glutPostRedisplay();
}

void keyboardFunc(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 27:
		{
			exit(0);
			break;
		}
	}
}

int main(int argc,char** argv)
{ 
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800,450);
	int in = glutCreateWindow("Soccer");
	Init();
	glutMouseFunc(ViewMouse);
	glutMotionFunc(ViewMouseMotion);
	glutKeyboardFunc(keyboardFunc);
	glutIdleFunc(idle);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

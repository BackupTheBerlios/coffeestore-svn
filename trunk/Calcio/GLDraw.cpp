#include "GLDraw.h"
#include "Ball.h"
#include "Player.h"
#include "Team.h"
#include "Field.h"

#include <GL/glut.h>
#include <cmath>

void GLDraw::draw(const Ball& ball)
{
	glPushAttrib(GL_CURRENT_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);

	drawFilledCircle(ball.position(), ball.radius());

	glPopAttrib();
}

void GLDraw::draw(const Team& team)
{
	glPushAttrib(GL_CURRENT_BIT);

	if (team.color() == Team::Color_RED)
		glColor3f(1.0f,0.0f,0.0f);
	if (team.color() == Team::Color_BLUE)
		glColor3f(0.0f,0.0f,1.0f);
	
	for (Team::PlayersConstIterator it = team.playersBegin(); it != team.playersEnd(); ++it)
		draw(*it);

	glPopAttrib();
}

void GLDraw::draw(const Player& player)
{
	drawFilledCircle(player.position(), player.radius());
}

void GLDraw::drawFilledCircle(const Point& point, float radius)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glScalef(450.0f/800.0f,1.0f,1.0f);
	glTranslatef(point.x(), point.y(), 0.0f);

	glBegin(GL_POLYGON);

	const float deg2rad = M_PI/180.0f;
	for (int i = 0; i < 360; i++)
	{
		float degInRad = i*deg2rad;
		glVertex2f(cos(degInRad) * radius, sin(degInRad) * radius);
	}

	glEnd();

	glPopMatrix();
}

void GLDraw::drawWire(const Rectangle& rectangle)
{
	glBegin(GL_LINE_LOOP);
		glVertex2f(rectangle.a().x(), rectangle.a().y());
		glVertex2f(rectangle.c().x(), rectangle.a().y());
		glVertex2f(rectangle.c().x(), rectangle.c().y());
		glVertex2f(rectangle.a().x(), rectangle.c().y());
	glEnd();
}

void GLDraw::draw(const Line& line)
{
	glBegin(GL_LINES);
		glVertex2f(line.a().x(), line.a().y());
		glVertex2f(line.b().x(), line.b().y());
	glEnd();
}

void GLDraw::draw(const Field& field)
{
	glPushAttrib(GL_CURRENT_BIT);
	glColor3f(1.0f,1.0f,1.0f);

	drawWire(field.boxLeft());
	drawWire(field.boxRight());
	drawWire(field.corner());
	draw(field.mid());

	glPopAttrib();
}

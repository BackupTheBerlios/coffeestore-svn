#include "Team.h"
#include <GL/glut.h>

Team::Team(SQUAD sq) : _sq(sq)
{
	_player.push_back(Player(Point(50.0f*_sq,0), 6));
}

void Team::run()
{
	_player[0].position().x()+= 0.1f*_sq;
}

void Team::draw()
{
	glPushAttrib(GL_CURRENT_BIT);
	
	if (TEAM_A == _sq)
		glColor3f(1.0f,0.0f,0.0f);
	else
		glColor3f(0.0f,0.0f,1.0f);

	_player[0].draw();
	glPopAttrib();
}


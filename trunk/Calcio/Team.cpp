#include "Team.h"
#include <GL/glut.h>

Team::Team(Color color)
	:	_color(color)
{
	if (_color == Color_RED)
		_player.push_back(Player(Point(50.0f,0), 6));
	else
		_player.push_back(Player(Point(50.0f*-1,0), 6));
}

Team::Color Team::color() const
{
	return _color;
}

void Team::run()
{
	if (_color == Color_RED)
		_player[0].position().x()+= 0.1f;
	else
		_player[0].position().x()+= 0.1f*-1;	
}

Team::PlayersConstIterator Team::playersBegin() const
{
	return _player.begin();
}

Team::PlayersConstIterator Team::playersEnd() const
{
	return _player.end();
}

Team::PlayersIterator Team::playersBegin()
{
	return _player.begin();
}

Team::PlayersIterator Team::playersEnd()
{
	return _player.end();
}

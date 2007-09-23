#ifndef TEAM_H
#define TEAM_H

#include <vector>

#include "Player.h"

class Team
{
	typedef std::vector<Player> Players;
public:
	typedef Players::const_iterator PlayersConstIterator;
	typedef Players::iterator PlayersIterator;

	enum Color
	{
		Color_BLUE, Color_RED
	};

	Team(Color color);

	Color color() const;

	void run();

	PlayersConstIterator playersBegin() const;
	PlayersConstIterator playersEnd() const;
	PlayersIterator playersBegin();
	PlayersIterator playersEnd();

private:
	Players _player;
	Color _color;
};

#endif

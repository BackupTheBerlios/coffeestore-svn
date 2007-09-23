#ifndef TEAM_H
#define TEAM_H

#include <vector>

class Player;

class Team
{
public:
	typedef std::vector<Player*> Players;
	typedef Players::const_iterator PlayersConstIterator;
	typedef Players::iterator PlayersIterator;

	enum Color
	{
		Color_BLUE, Color_RED
	};

	enum Side
	{
		Side_LEFT = 1, Side_RIGHT = -1
	};


	Team(Color color, Side side);

	Color color() const;
	Side side() const;

	void run();

	PlayersConstIterator playersBegin() const;
	PlayersConstIterator playersEnd() const;
	PlayersIterator playersBegin();
	PlayersIterator playersEnd();

private:
	Players _player;
	Color  _color;
	Side _side;
};

#endif

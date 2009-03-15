#ifndef TEAM_H
#define TEAM_H

#include <vector>

class Player;
class AbstractPlayersFactory;

class Team
{
public:
	typedef std::vector<Player*> Players;
	typedef Players::const_iterator PlayersConstIterator;
	typedef Players::iterator PlayersIterator;

	enum Color
	{
		Color_BLUE, 
		Color_RED
	};

	enum Side
	{
		Side_LEFT = 1, 
		Side_RIGHT = -1
	};

	Team(Color color, Side side, AbstractPlayersFactory& factory);
	~Team();

	Color color() const;
	Side side() const;

	PlayersConstIterator playersBegin() const;
	PlayersConstIterator playersEnd() const;
	PlayersIterator playersBegin();
	PlayersIterator playersEnd();

private:
	void init(AbstractPlayersFactory& teamFactory);

	AbstractPlayersFactory& _factory;
	Players _players;
	Color  _color;
	Side _side;
};

#endif

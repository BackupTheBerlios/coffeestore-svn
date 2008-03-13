#include <algorithm>
#include "Team.h"
#include "Player.h"
#include "AbstractPlayer.h"
#include "AbstractPlayersFactory.h"
#include "Convertion.h"

class PlayerConverter
{
public:

	AbstractPlayer* operator()(Player* pl)
	{
		return &pl->abstractPlayer();
	}
};

Team::Team(Color color, Side side,AbstractPlayersFactory& fact)
	:	_color(color), _side(side),_fact(fact)
{
	init(fact);
}

void Team::init(AbstractPlayersFactory& teamFactory)
{
	std::vector<AbstractPlayer*> pl = teamFactory.createPlayers();
	for(std::vector<AbstractPlayer*>::iterator it = pl.begin();it != pl.end();++it)
	{
		Player* tmp = new Player(*(*it));
		tmp->position() = Convertion::toAbsoultePosition((*it)->position(),_side);
 		_players.push_back(tmp);
	}
}

Team::Color Team::color() const
{
	return _color;
}

Team::Side Team::side() const
{
	return _side;
}

Team::PlayersConstIterator Team::playersBegin() const
{
	return _players.begin();
}

Team::PlayersConstIterator Team::playersEnd() const
{
	return _players.end();
}

Team::PlayersIterator Team::playersBegin()
{
	return _players.begin();
}

Team::PlayersIterator Team::playersEnd()
{
	return _players.end();
}

Team::~Team()
{
	std::vector<AbstractPlayer*> vct(_players.size());
	std::transform(playersBegin(),playersEnd(),vct.begin(),PlayerConverter());
	_fact.destroyPlayers(vct);
	
	for(unsigned int ii = 0;ii < _players.size();++ii)
		delete _players[ii];
}
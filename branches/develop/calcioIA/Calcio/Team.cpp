#include "Team.h"
#include "Player.h"
#include "AbstractPlayer.h"
#include "AbstractPlayersFactory.h"
#include "Convertion.h"

Team::Team(Color color, Side side, AbstractPlayersFactory& factory)
	:	_color(color), _side(side), _factory(factory)
{
	init(factory);
}

Team::~Team()
{
	std::vector<AbstractPlayer*> abstractPlayers;
	for (Team::PlayersIterator it = playersBegin(); it != playersEnd(); ++it)
	{
		Player* player = *it;
		abstractPlayers.push_back(&player->abstractPlayer());
		delete player;
	}

	_factory.destroyPlayers(abstractPlayers);
}

void Team::init(AbstractPlayersFactory& teamFactory)
{
	std::vector<AbstractPlayer*> pl = teamFactory.createPlayers();
	for(std::vector<AbstractPlayer*>::iterator it = pl.begin(); it != pl.end(); ++it)
	{
		Player* tmp = new Player(*(*it));
		tmp->position() = Convertion::toAbsoultePosition((*it)->initialPosition(), _side);
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

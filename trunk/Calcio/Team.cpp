#include "Team.h"
#include "Player.h"
#include "AbstractPlayer.h"
#include "PlayerFactory.h"
#include "Convertion.h"

Team::Team(Color color, Side side)
	:	_color(color), _side(side)
{

}

void Team::init(PlayerFactory& playerFactory)
{
	Player* player = new Player(playerFactory.create(1));
	player->position() = Convertion::toAbsoultePosition(player->abstractPlayer().position(), _side);
	_players.push_back(player);
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

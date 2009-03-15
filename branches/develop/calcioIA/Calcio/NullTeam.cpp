#include "NullTeam.h"

NullPlayer::NullPlayer()
	:	AbstractPlayer(Point(), 1)
{

}

void NullPlayer::run(const Perceptions& perceptions, PlayerAction& playerAction)
{

}

std::vector<AbstractPlayer*> NullTeamFactory::createPlayers()
{
	std::vector<AbstractPlayer*> res;
	res.push_back(new NullPlayer());
	return res;
}

void NullTeamFactory::destroyPlayers(std::vector<AbstractPlayer*>& plys)
{
	delete plys.front();
}

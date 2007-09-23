#ifndef TEAM_FACTORY_H
#define TEAM_FACTORY_H

class AbstractPlayer;

class TeamFactory
{
public:
	virtual AbstractPlayer& createPlayer(int number) = 0;
};

#endif

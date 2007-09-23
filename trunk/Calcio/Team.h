#ifndef TEAM_H
#define TEAM_H

#include <vector>

#include "Player.h"

class Team
{
public:
	enum SQUAD{TEAM_A=-1,TEAM_B=1};
	Team(SQUAD s);

	void run();

	void draw();
private:
	std::vector<Player> _player;
	SQUAD _sq;
};

#endif

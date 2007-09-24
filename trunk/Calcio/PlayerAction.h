#ifndef PLAYER_ACTION_H
#define PLAYER_ACTION_H

#include "Vector.h"
#include "Team.h"

class PlayerAction
{
public:
	PlayerAction(Team::Side side);

	void doRun(const Vector& r);
	void doKick(const Vector& k);

	const Vector& run() const;
	const Vector& kick() const;

private:
	Vector _run;
	Vector _kick;

	Team::Side _side;
};

#endif

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
	void doTurnHead(const float angle);

	const Vector& run() const;
	const Vector& kick() const;
	const Vector& sightDirection() const;

private:
	Vector _run;
	Vector _kick;
	Vector _see;

	Team::Side _side;
};

#endif

#ifndef DUMMY_PLAYER_H
#define DUMMY_PLAYER_H

#include "Player.h"

class DummyPlayer : public Player
{
public:
	DummyPlayer(const Point& initialPosition, int number);

	void run(const Perceptions& perceptions, PlayerAction& playerAction);
};

#endif

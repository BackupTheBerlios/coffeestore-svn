#ifndef DUMMY_PLAYER_H
#define DUMMY_PLAYER_H

#include "AbstractPlayer.h"

class DummyPlayer : public AbstractPlayer
{
public:
	DummyPlayer(const Point& initialPosition, int number);

	void run(const Perceptions& perceptions, PlayerAction& playerAction);
};

#endif

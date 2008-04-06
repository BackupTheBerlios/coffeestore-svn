#include "PerceivedPlayer.h"

PerceivedPlayer::PerceivedPlayer(const Point& pos, int number)
	:_pos(pos), _number(number)
{

}

int PerceivedPlayer::number() const
{
	return _number;
}

const Point& PerceivedPlayer::position() const
{
	return _pos;
}
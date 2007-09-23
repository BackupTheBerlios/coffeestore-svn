#include "PerceivedPlayer.h"

PerceivedPlayer::PerceivedPlayer(const Point& pos)
:_pos(pos)
{

}

const Point& PerceivedPlayer::position() const
{
	return _pos;
}
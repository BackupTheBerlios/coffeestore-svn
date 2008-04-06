#include "AbstractPlayer.h"

AbstractPlayer::AbstractPlayer(const Point& initialPosition, int number)
	:	_initialPosition(initialPosition), _number(number)
{

}

const Point& AbstractPlayer::position() const
{
	return _initialPosition;
}

int AbstractPlayer::number() const
{
	return _number;
}

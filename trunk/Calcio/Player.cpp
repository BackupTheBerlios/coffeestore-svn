#include "Player.h"

Player::Player(const Point& initialPosition, int number)
	:	_initialPosition(initialPosition), _number(number)
{

}

const Point& Player::position() const
{
	return _initialPosition;
}

int Player::number() const
{
	return _number;
}

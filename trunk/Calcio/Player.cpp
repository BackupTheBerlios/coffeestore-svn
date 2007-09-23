#include "Player.h"

Player::Player(const AbstractPlayer& player)
	:	_player(player), _radius(3)
{

}

const AbstractPlayer& Player::abstractPlayer() const
{
	return _player;
}

Point& Player::position()
{
	return _position;
}

const Point& Player::position() const
{
	return _position;
}

float Player::radius() const
{
	return _radius;
}

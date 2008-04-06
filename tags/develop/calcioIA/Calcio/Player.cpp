#include "Player.h"

Player::Player(AbstractPlayer& player)
	:	_player(player), _radius(3)
{

}

AbstractPlayer& Player::abstractPlayer()
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

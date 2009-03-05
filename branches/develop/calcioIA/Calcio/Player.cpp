#include "Player.h"

Player::Player(AbstractPlayer& player)
	:	_player(player), _radius(3),_see(1.0f,0.0f)
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

const Vector& Player::sightDirection() const
{
	return _see;
}

void Player::sightDirection(const Vector& dir)
{
	_see = dir.normalize();
}
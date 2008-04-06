#ifndef PERCEIVEDPLAYER_H
#define PERCEIVEDPLAYER_H

#include "Point.h"

class PerceivedPlayer
{
public:
	PerceivedPlayer(const Point& pos, int number);
	const Point& position() const;
	int number() const;
private:
	int _number;
	Point _pos;
};

#endif
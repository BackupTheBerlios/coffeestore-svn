#ifndef PERCEIVEDPLAYER_H
#define PERCEIVEDPLAYER_H

#include "Point.h"

class PerceivedPlayer
{
public:
	PerceivedPlayer(const Point& pos);
	const Point& position() const;
private:
	Point _pos;
};

#endif
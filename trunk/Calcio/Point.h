#ifndef POINT_H
#define POINT_H

#include <iosfwd>

class Point
{
public:
	Point();
	Point(float x, float y);

	float x() const;
	float y() const;
	float& x();
	float& y();

	void set(float x, float y);
	
private:
	float _p[2];
};

Point operator - (const Point& p1, const Point& p2);
Point operator * (float f, const Point& p);
Point operator * (const Point& p, float f);
Point operator + (const Point& p1, const Point& p2);
Point operator / (const Point& p, float f);


std::ostream& operator << (std::ostream& os, const Point& point);

#endif

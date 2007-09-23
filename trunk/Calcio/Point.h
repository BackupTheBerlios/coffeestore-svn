#ifndef POINT_H
#define POINT_H

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

	operator float*()
	{
		return _p;
	}

private:
	float _p[2];
};

#endif

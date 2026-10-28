#include "vect2.hpp"

vect2::vect2() : _x(0), _y(0) {}
vect2::vect2(int x, int y) : _x(x), _y(y) {}
vect2::vect2(const vect2 &other) : _x(other._x), _y(other._y) {}
vect2::~vect2() {}

vect2& vect2::operator=(const vect2 &other)
{
	if (this != &other)
	{
		_x = other._x;
		_y = other._y;
	}
	return (*this);
}

int& vect2::operator[](const int index)
{
	if (index ==0)
		return (_x);
	return (_y);
}

const int& vect2::operator[](const int index) const
{
	if (index ==0)
		return (_x);
	return (_y);
}




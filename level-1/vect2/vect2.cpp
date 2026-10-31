#include "vect2.hpp"

vect2::vect2() : _x(0), _y(0) {}
vect2::vect2(int a, int b) : _x(a), _y(b) {}
vect2::vect2(const vect2& obj) : _x(obj._x), _y(obj._y) {}
vect2::~vect2() {}

vect2& vect2::operator=(const vect2& obj)
{
	if (*this != obj)
	{
		_x = obj._x;
		_y = obj._y;
	}
	return (*this);
}

vect2 vect2::operator*(int s) const
{
	return (vect2(_x * s, _y * s));
}

vect2& vect2::operator*=(int s)
{
	_x *= s;
	_y *= s;
	return (*this);
}
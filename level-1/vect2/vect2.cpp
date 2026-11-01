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

vect2 vect2::operator+(const vect2& obj) const
{
	return (vect2(_x + obj._x, _y + obj._y));
}

vect2 vect2::operator-(const vect2& obj) const
{
	return (vect2(_x - obj._x, _y - obj._y));
}

vect2 vect2::operator*(const vect2& obj) const
{
	return (vect2(_x * obj._x, _y * obj._y));
}

vect2& vect2::operator+=(const vect2& obj)
{
	vect2 tmp(*this);
	_x += obj._x;
	_y += obj._y;
	return (*this);
}

vect2& vect2::operator-=(const vect2& obj)
{
	vect2 tmp(*this);
	_x -= obj._x;
	_y -= obj._y;
	return (*this);
}

vect2& vect2::operator*=(const vect2& obj)
{
	vect2 tmp(*this);
	_x *= obj._x;
	_y *= obj._y;
	return (*this);
}

vect2& vect2::operator++()
{
	_x += 1;
	_y += 1;
	return (*this);
}

vect2 vect2::operator++(int)
{
	++(*this);
	return (tmp);
}

vect2& vect2::operator--()
{
	_x -= 1;
	_y -= 1;
	return (*this);
}

vect2 vect2::operator--(int)
{
	--(*this);
	return (tmp);
}

bool vect2::operator==(const vect2& obj) const
{
	return (_x == obj._x && _y == obj._y);
}

bool vect2::operator!=(const vect2& obj) const
{
	return (!(*this == obj));
}

int vect2::operator[](int index) const
{
	if (index == 0)
		return (_x);
	return (_y);
}

int& vect2::operator[](int index)
{
	if (index == 0)
		return (_x);
	return (_y);
}

vect2 vect2::operator-() const
{
	return (vect2(-_x, -_y));
}

vect2 operator*(int s, const vect2& obj)
{
	return (obj * s);
}

std::ostream& operator<<(std::ostream& out, const vect2& obj)
{
	out << "{" << obj[0] << ", " << obj[1] << "}";
	return (out);
}
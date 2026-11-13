#include "vect2.hpp"

vect2::vect2() : x(0), y(0) {}
vect2::vect2(int a, int b) : x(a), y(b) {}
vect2::vect2(const vect2& v) : x(v.x), y(v.y) {}
vect2::~vect2() {}

vect2& vect2::operator=(const vect2& v)
{
	if (this != &v)
	{
		x = v.x;
		y = v.y;
	}
	return *this;
}

vect2 vect2::operator-() const
{
	return (vect2(-x, -y));
}

vect2& vect2::operator*=(int s)
{
	x *= s;
	y *= s;
	return *this;
}

vect2 vect2::operator*(int s) const
{
	return (vect2(x * s, y * s));
}

vect2& vect2::operator+=(const vect2& v)
{
	x += v.x;
	y += v.y;
	return *this;
}

vect2& vect2::operator-=(const vect2& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

vect2 vect2::operator+(const vect2& v) const
{
	return (vect2(x + v.x, y + v.y));
}

vect2 vect2::operator-(const vect2& v) const
{
	return (vect2(x - v.x, y - v.y));
}

int& vect2::operator[](int i)
{
	if (i == 0)
		return x;
	return y;
}

const int& vect2::operator[](int i) const
{
	if (i == 0)
		return x;
	return y;
}

bool vect2::operator==(const vect2& v) const
{
	return (x == v.x && y == v.y);
}

bool vect2::operator!=(const vect2& v) const
{
	return !(*this == v);
}

vect2& vect2::operator++()
{
	++x;
	++y;
	return *this;
}

vect2 vect2::operator++(int)
{
	vect2 temp(*this);
	++(*this);
	return temp;
}

vect2& vect2::operator--()
{
	--x;
	--y;
	return *this;
}

vect2 vect2::operator--(int)
{
	vect2 temp(*this);
	--(*this);
	return temp;
}

vect2 operator*(int s, const vect2& v)
{
	return (vect2(v[1] * s, v[2] * s));
}

std::ostream& operator<<(std::ostream& o, const vect2& v)
{
	o << "(" << v[1] << ", " << v[2] << ")";
	return o;
}
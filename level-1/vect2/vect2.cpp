<<<<<<< HEAD
#include "vect2.hpp"

vect2::vect2() : x(0), y(0) {}
vect2::vect2(int a, int b) : x(a), y(b) {}
vect2::vect2(const vect2& obj) : x(obj.x), y(obj.y) {}

vect2& vect2::operator=(const vect2& obj)
{
	if (this != &obj)
	{
		x = obj.x;
		y = obj.y;
	}
	return *this;
}

vect2 vect2::operator-() const
{
	return vect2(-x, -y);
}

vect2 vect2::operator*(int s) const
{
	return vect2(x * s, y * s);
}

vect2& vect2::operator*=(int s)
{
	x *= s;
	y *= s;
	return *this;
}

vect2 vect2::operator+(const vect2& obj) const
{
	return vect2(x + obj.x, y + obj.y);
}

vect2 vect2::operator-(const vect2& obj) const
{
	return vect2(x - obj.x, y - obj.y);
}

vect2& vect2::operator+=(const vect2& obj)
{
	x += obj.x;
	y += obj.y;
	return *this;
}

vect2& vect2::operator-=(const vect2& obj)
{
	x -= obj.x;
	y -= obj.y;
	return *this;
}

bool vect2::operator==(const vect2& obj) const
{
	return (x == obj.x && y == obj.y);
}

bool vect2::operator!=(const vect2& obj) const
{
	return !(*this == obj);
}

int& vect2::operator[](int index)
{
	if (index == 0)
		return x;
	else if (index == 1)
		return y;
	else
		throw std::out_of_range("Index out of range");
}

const int& vect2::operator[](int index) const
{
	if (index == 0)
		return x;
	else if (index == 1)
		return y;
	else
		throw std::out_of_range("Index out of range");
}

vect2 vect2::operator++(int)
{
	vect2 temp(*this);
	++(*this);
	return temp;
}

vect2& vect2::operator++()
{
	++x;
	++y;
	return *this;
}

vect2 vect2::operator--(int)
{
	vect2 temp(*this);
	--(*this);
	return temp;
}

vect2& vect2::operator--()
{
	--x;
	--y;
	return *this;
}

vect2 operator*(int s, const vect2& obj)
{
	return obj * s;
}

std::ostream& operator<<(std::ostream& out, const vect2& obj)
{
	out << "(" << obj[0] << ", " << obj[1] << ")";
	return out;
}
=======
#include "vect2.hpp"

vect2::vect2() : _x(0), _y(0) {}
vect2::vect2(int x, int y) : _x(x), _y(y) {}
vect2::vect2(const vect2& obj) : _x(obj._x), _y(obj._y) {}

vect2::vect2(const vect2& obj)
{
    if (this != &obj)
    {
        _x = obj._x;
        _y = obj._y;
    }
    return (*this);
}

vect2 operator-() const
{
    _x = -_x;
    _y = -_y;
    return (this);
}
>>>>>>> deed2668c3eda9e00a6181fab2f5df15bcf96b00

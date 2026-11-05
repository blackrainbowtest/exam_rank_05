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

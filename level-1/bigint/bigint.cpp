#include "bigint.hpp"

bigint::bigint() : value(0) {}
bigint::bigint (unsigned int v)
{
	std::stringstream ss;

	ss << v;
	_data = ss.str();
}
bigint::bigint(const bigint& obj) : _data(obj._data) {}
bigint::~bigint() {}

bigint& bigint::operator=(const bigint& obj)
{
	if (this != &obj)
	{
		_data = obj._data;
	}
	return (*this);
}

// == != > < >= <=
bool bigint::operator==(const bigint& obj) const
{
	return (_data == obj._data);
}

bool bigint::operator!=(const bigint& obj) const
{
	return (!(*this == obj));
}

bool bigint::operator<(const bigint& obj) const
{
	if(_data.size() != obj._data.size())
		return (_data.size() < obj._data.size());
	return (_data < obj._data);
}

bool bigint::operator>(const bigint& obj) const
{
	return (obj < *this);
}

bool bigint::operator<=(const bigint& obj) const
{
	return (!(*this > obj));
}

bool bigint::operator>=(const bigint& obj) const
{
	return (!(*this < obj));
}

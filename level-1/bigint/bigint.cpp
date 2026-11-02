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

bigint bigint::operator+(const bigint& obj) const
{
	bigint result;
	std::string res;

	int i = _data.size() -1;
	int j = obj._data.size() -1;
	int carry = 0;

	while (i >= 0 || j >= 0 || carry)
	{
		int sum = carry;
		if (i >= 0)
			sum += _data[i--] -'0';
		if (j >= 0)
			sum += obj._data[j--] - '0';
		res.insert(res.begin(), (sum % 10) + '0');

		carry = sum / 10;
	}

	result._data = res;
	return (result);
}
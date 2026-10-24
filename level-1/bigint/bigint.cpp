#include "bigint.hpp"
#include <sstream>

bigint::bigint() : _data ("0") {}

bigint::bigint(unsigned int num)
{
	std::stringstream ss;

	ss << num;
	_data = ss.str();
}

bigint::bigint(const bigint &other) : _data(other._data) {}

bigint::~bigint() {}

bigint bigint::operator=(const bigint &other)
{
	if (this != &other)
	{
		_data = other._data;
	}
	return *this;
}

std::string bigint::getStr(void) const
{
	return _data;
}

std::string bigint::_reverse(const std::string &str) const
{
	std::string reversedStr = str;

	for (int i = str.size(); i > 0; i--)
		reversedStr[str.size() - i] = str[i - 1];
	return reversedStr;
}


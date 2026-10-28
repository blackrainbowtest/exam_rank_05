#include "bigint.hpp"

bigint::bigint() : _value("0") {}
bigint::bigint(unsigned int num)
{
	std::stringstream ss;

	ss << num;
	_value = ss.str();
}
bigint::bigint(const bigint &other) : _value(other._value) {}
bigint::~bigint() {}

bigint& bigint::operator=(const bigint &other)
{
	if (this != &other)
		_value = other._value;
	return (*this);
}

static unsigned int stringToUINT(const std::string &str)
{
	std::stringstream ss(str);
	unsigned int res = 0;

	ss >> res;
	return (res);
}

// operator
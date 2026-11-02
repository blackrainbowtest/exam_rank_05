#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <sstream>
#include <string>

class bigint
{
	private:
		std::string _data;
	public:
		bigint();
		bigint(unsigned int num);
		bigint(const bigint& obj);
		~bigint();

		bigint& operator=(const bigint& obj);

		bool operator==(const bigint& obj) const;
		bool operator!=(const bigint& obj) const;

		bool operator<(const bigint& obj) const;
		bool operator>(const bigint& obj) const;
		bool operator<=(const bigint& obj) const;
		bool operator>=(const bigint& obj) const;
};

std::ostream operator<<(std::ostream& out, const bigint& obj);

#endif


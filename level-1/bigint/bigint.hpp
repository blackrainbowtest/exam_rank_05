#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <sstream>
#include <string>

class bigint
{
	private:
		std::string digits;
	public:
		bigint();
		bigint(unsigned int num);
		bigint(const bigint& b);
		~bigint();

		bigint& operator=(const bigint& b);

		bigint& operator+=(const bigint& b);
		bigint  operator+(const bigint& b) const;
		bigint& operator++();
		bigint  operator++(int);

		// << <<=
		bigint& operator<<=(unsigned int s);
		bigint& operator<<=(const bigint& b);
		bigint  operator<<(unsigned int s) const;
		bigint  operator<<(const bigint& b) const;
		// >> >>=
		bigint& operator>>=(unsigned int s);
		bigint& operator>>=(const bigint& b);
		bigint  operator>>(unsigned int s) const;
		bigint  operator>>(const bigint& b) const;
		// < <=
		bool  operator<(const bigint& b) const;
		bool operator<=(const bigint& b) const;
		// > >=
		bool  operator>(const bigint& b) const;
		bool operator>=(const bigint& b) const; 
		// == !=
		bool operator==(const bigint& b) const;
		bool operator!=(const bigint& b) const;
		// getter
		const std::string& getDigits() const;
};

std::ostream& operator<<(std::ostream& o, const bigint& b);

#endif

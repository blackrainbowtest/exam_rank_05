#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <sstream>

class bigint
{
	private:
		std::string _data;
	
	public:
		bigint();
		bigint(unisgned int num);
		bigint(const bigint &other);

		bigint operator=(const bigint &other);
		
		std::string getStr()const;

		bigint operator+(const bigint const &other) const;
		bigint &operator+=(const bigint &other);

		bigint &operator++();
		bigint operator++(int);

		bigint operator<<(unsigned int num) const;
		bigint operator>>(unsigned int num) const;
		bigint &operator<<=(unsigned int num);
		bigint &operator>>=(unsigned int num);

		bigint operator<<(const bigint &other) const;
		bigint operator>>(const bigint &other) const;
		bigint &operator<<=(const bigint &other);
		bigint &operator>>=(const bigint &other);


};

#endif // BIGINT_HPP

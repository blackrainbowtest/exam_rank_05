#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
	private:
		int x;
		int y;
	public:
		vect2();
		vect2(int a, int b);
		vect2(const vect2& v);
		~vect2();

		vect2& operator=(const vect2& v);

		vect2& operator*=(int s);
		vect2  operator*(int s) const;

		vect2& operator+=(const vect2& v);
		vect2& operator-=(const vect2& v);
		vect2  operator+(const vect2& v) const;
		vect2  operator-(const vect2& v) const;

		int& operator[](int i);
		const int& operator[](int i) const;

		bool operator==(const vect2& v) const;
		bool operator!=(const vect2& v) const;

		vect2& operator++();
		vect2  operator++(int);
		vect2& operator--();
		vect2  operator--(int);

		vect2  operator-() const;

};

vect2 operator*(int s, const vect2& v);
std::ostream& operator<<(std::ostream& o, const vect2& v);

#endif

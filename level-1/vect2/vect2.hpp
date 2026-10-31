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
		vect2(int x, int y);
		vect2(const vect2& obj);
		~vect2();

		vect2& operator=(const vect2& obj);

		vect2 operator*(int s) const;
		vect2& operator*=(int s);

		vect2 operator+(const vect2& obj) const;
		vect2 operator-(const vect2& obj) const;
		vect2 operator*(const vect2& obj) const;

		vect2& operator+=(const vect2& obj);
		vect2& operator-=(const vect2& obj);
		vect2& operator*=(const vect2& obj);

		int operator[](int index) const;
		int& operator[](int index);

		vect2& operator++();
		vect2 operator++(int);
		vect2& operator--();
		vect2 operator--(int);

		bool operator==(const vect2& obj) const;
		bool operator!=(const vect2& obj) const;
};

vect2 operator*(int s, const vect2& obj);
std::ostream& operator<<(std::ostream& out, const vect2& obj);

#endif
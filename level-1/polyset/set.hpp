#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set
{
	searchable_bag *bag;
	public:
		set();
		set(searchable_bag& b);
		set(const set& s);
		set& operator=(const set& s);
		~set();

		void insert(int v);
		void insert(int* v, int n);
		void print() const;
		void clear();
		bool has(int v) const;

		const searchable_bag& get_bag() const;
		searchable_bag& get_bag();
};

#endif
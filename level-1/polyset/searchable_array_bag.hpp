#ifndef searchable_array_bag_HPP
#define searchable_array_bag_HPP

#include "array_bag.hpp"
#include "serchable_bag.hpp"

class searchable_array_bag : public array_bag, public serchable_bag
{
	public:
		searchable_array_bag();
		searchable_array_bag(const searchable_array_bag& b);
		searchable_array_bag& operator=(const searchable_array_bag& b);
		~searchable_array_bag();

		bool has(int v) const;
};

#endif
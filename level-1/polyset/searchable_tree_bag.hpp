#ifndef searchable_tree_bag_HPP
#define searchable_tree_bag_HPP

#include "tree_bag.hpp"
#include "serchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public serchable_bag
{
	public:
		searchable_tree_bag();
		searchable_tree_bag(const searchable_tree_bag& b);
		searchable_tree_bag& operator=(const searchable_tree_bag& b);
		~searchable_tree_bag();

		bool has(int v) const;
};

#endif
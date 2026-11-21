#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() : tree_bag() {}
searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& b) : tree_bag(b) {}
searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& b)
{
	if (this != &b)
	{
		tree_bag::operator=(b);
	}
	return *this;
}
searchable_tree_bag::~searchable_tree_bag() {}

bool searchable_tree_bag::has(int v) const
{
	node const *current = tree;
	while (current != 0)
	{
		if (current->value == v)
			return (true);
		if (v < current->value)
			current = current->l;
		else
			current = current->r;
	}
	return (false);
}
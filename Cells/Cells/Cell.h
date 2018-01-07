#pragma once

// TODO find best practice for setting north, south, east, west pointers
// TODO Fix Binary Tree Algorithm
// TODO Find best practice for char body
// TODO

#include <forward_list>

class Cell
{
	std::forward_list<Cell*> links;

public:
	Cell() {}

	void link(Cell&, bool bidi = true);
	void unlink(Cell&, bool bidi = true);
	bool isLinked(const Cell&) const;
	bool noLinks() const;
};


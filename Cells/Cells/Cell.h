#pragma once

// TODO find best practice for setting north, south, east, west pointers
// TODO Fix Binary Tree Algorithm
// TODO Find best practice for char body
// TODO

#include <forward_list>
#include <iostream>
#include <string>

class Cell
{
	std::forward_list<Cell*> links;
	std::forward_list<Cell*> neighbors;
	Cell * north = nullptr;
	Cell * south = nullptr;
	Cell * east = nullptr;
	Cell * west = nullptr;

public:
	Cell() {}

	void link(Cell&, bool bidi = true);
	void unlink(Cell&, bool bidi = true);
	bool isLinked(const Cell&) const;
	std::forward_list<Cell*> const& getLinks() const { return links; }
};


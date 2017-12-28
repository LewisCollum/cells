#pragma once

// TODO find best practice for setting north, south, east, west pointers
// TODO Fix Binary Tree Algorithm
// TODO Find best practice for char body
// TODO

#include <forward_list>
#include <ostream>
#include <string>

class Cell
{
	char body = ' ';
	std::forward_list<Cell> links;
	Cell *north = nullptr;
	Cell *south = nullptr;
	Cell *east = nullptr;
	Cell *west = nullptr;

public:
	Cell() {}


	bool operator==(const Cell &c) const {
		return &(*this) == &c;
	}
	
	//char setBody(char b) { body = b; return body; }
	//char const& getBody() const { return body; }

	

	void occupy() {}
	void deoccupy() {}

	void link(Cell&, bool);
	void unlink(Cell&, bool);
	bool isLinked(const Cell&) const;
};


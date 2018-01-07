#pragma once

#include <array>
#include <ostream>
#include "Cell.h"
#include <string>

// Forward Declarations (Necessary for friends of template class)
template<std::size_t COLS, std::size_t ROWS> class Grid;
template<std::size_t COLS, std::size_t ROWS> std::ostream& operator<<(std::ostream& output, Grid<COLS, ROWS>& g);

// Class Definition
template<std::size_t COLS, std::size_t ROWS>
class Grid
{
	// TODO : make "Grid<COLS, ROWS>& g" const and implement const [] operators
	// overload for writing Grid to screen (Ignore Visual Studio's Warning)
	friend std::ostream& operator<< <>(std::ostream& output, Grid<COLS, ROWS>& g);

protected:

	std::array<std::array<Cell, COLS>, ROWS> grid;
	virtual std::array<std::array<Cell, COLS>, ROWS> prepareGrid(std::array<std::array<Cell, COLS>, ROWS>& g);

	bool isNorth(int index) { return index != 0; }
	bool isEast(int index) { return index != COLS - 1; }
	bool isSouth(int index) { return index != ROWS - 1; }
	bool isWest(int index) { return index != 0; }

public:
	Grid();
	enum { NORTH, SOUTH, EAST, WEST };
	size_t size() const { return grid.size(); }

	// Subscripting [][] overloads
	class Proxy {
		std::array<Cell, COLS>& gridRow;
	public:
		Proxy(std::array<Cell, COLS>& a) : gridRow(a) {}
		Cell& operator[](size_t i) { return gridRow[i]; }
		size_t size() const { return gridRow.size(); }
	};

	Proxy operator[](size_t i) { return Proxy(grid[i]); }
};

// CONSTRUCTOR
template<std::size_t COLS, std::size_t ROWS>
Grid<COLS, ROWS>::Grid()
{
	//prepareGrid(grid);
}

// PREPARE GRID
template<std::size_t COLS, std::size_t ROWS>
std::array<std::array<Cell, COLS>, ROWS> Grid<COLS, ROWS>::prepareGrid(std::array<std::array<Cell, COLS>, ROWS>& g)
{
	// TODO : make cell pointers instead and instantiate Cell only when needed
	// This will allow us to create memory efficient non-rectangular grids
	for (auto i = g.begin(); i != g.end(); ++i)
		for (auto j = i->begin(); j != i->end(); ++j)
			*j = Cell();


	return g;
}


// WRITE GRID TO STREAM
template<std::size_t COLS, std::size_t ROWS>
std::ostream& operator<<(std::ostream& output, Grid<COLS, ROWS>& g)
{
	// top border
	output << "+";
	for (int i = 0; i < g[0].size(); ++i) output << "---+";
	output << "\n";

	for (int row = 0; row != g.size(); ++row) {  // for each row...

		std::string mid = "|";
		std::string bottom = "+";

		//if (row == g.size() - 1) bottom = "+";
		//else bottom = "|";

		for (int col = 0; col != g[row].size(); ++col) {  // for each column in row...

			std::string body = "   ";
			std::string corner = "+";
			
			/*
			if (row == g.size() - 1) corner = "+";
			else {
				if (col == g[row].size() - 1) corner = "|";
				else {
					bool Lside = g[row][col].isLinked(g[row + 1][col]);
					bool Tside = g[row][col].isLinked(g[row][col + 1]);
					bool Bside = g[row + 1][col].isLinked(g[row + 1][col + 1]);
					bool Rside = g[row][col + 1].isLinked(g[row + 1][col + 1]);
					bool TLcorner = Tside && Lside;
					bool TRcorner = Tside && Rside;
					bool BLcorner = Bside && Lside;
					bool BRcorner = Bside && Rside;
					bool Thorizontal = (Tside & !Lside & !Rside & !Bside) || (Bside & !Lside & !Rside & !Tside);
					bool Tvertical = (!Tside & Lside & !Rside & !Bside) || (!Bside & !Lside & Rside & !Tside);

					if (Tside & Lside & Rside & Bside) corner = " ";
					else if ((Lside && Rside) || Tvertical) corner = "|";
					else if ((Tside && Bside) || Thorizontal) corner = "-";
					else {
						corner = "+";
					}
				}
			}
			*/
			

			std::string east_boundary;

			bool isEast = (col != g[row].size() - 1 && g[row][col].isLinked(g[row][col + 1]));

			east_boundary = (isEast ? " " : "|");
			
			// Concatenate body and east_boundary to the top
			mid += body + east_boundary;

			std::string south_boundary;

			bool isSouth = (row != g.size() - 1 && g[row][col].isLinked(g[row + 1][col]));

			south_boundary = isSouth ? "   " : "---"; // three spaces "   " : "---"

													  // Concatenate south_boundary and corner to the bottom
			bottom += south_boundary + corner;

		}

		output << mid << "\n";
		output << bottom << "\n";
	}

	return output;
}
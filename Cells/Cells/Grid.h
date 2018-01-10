#pragma once

#include <array>
#include <ostream>
#include <string>
#include "Cell.h"

/*
 * TODO : Implement bounds checking
 * TODO : Implement a pointer array in order to save memory if not all Cells are implemented
 * TODO : Implement Grid to be non-rectangular
 */

// Forward Declarations (Necessary for friends of template class)
template<class CellType, size_t COLS, size_t ROWS> class Grid;
// TODO : Move overload to another class
template<class CellType, size_t COLS, size_t ROWS> std::ostream& operator<<(std::ostream& output, const Grid<CellType, COLS, ROWS>& g);


template<class CellType, size_t COLS, size_t ROWS>
class Grid
{
	friend std::ostream& operator<< <>(std::ostream& output, const Grid<CellType, COLS, ROWS>& g);

public:
	using size_type = size_t;
	using reference = CellType&;
	using const_reference = const CellType&;

	constexpr enum { NORTH, SOUTH, EAST, WEST };

protected:
	std::array<std::array<CellType, COLS>, ROWS> grid;
	/*
	virtual std::array<std::array<CellType, COLS>, ROWS> prepareGrid(std::array<std::array<CellType, COLS>, ROWS>& g)
	{
		// TODO : make cell pointers instead and instantiate Cell only when needed
		// This will allow us to create memory efficient non-rectangular grids
		for (auto i = g.begin(); i != g.end(); ++i)
			for (auto j = i->begin(); j != i->end(); ++j)
				*j = new CellType();

		return g;
	}
	*/

	constexpr bool isNorth(int index) const { return index != 0; }
	constexpr bool isEast(int index) const { return index != COLS - 1; }
	constexpr bool isSouth(int index) const { return index != ROWS - 1; }
	constexpr bool isWest(int index) const { return index != 0; }

public:
	Grid() {}

	class Proxy {
		const std::array<CellType, COLS>& gridRow;
	public:
		constexpr explicit Proxy(const std::array<CellType, COLS>& a) : gridRow(a) {}
		// size (length) of columns
		constexpr size_type size() const { return gridRow.size(); }
		// index of columns
		constexpr const_reference operator[](size_type i) const { return gridRow[i]; }
	};
	// size (length) of rows
	constexpr size_type size() const { return grid.size(); }
	// index of rows
	constexpr Proxy operator[](size_type i) const { return Proxy(grid[i]); }
};

template<class CellType, size_t COLS, size_t ROWS>
std::ostream& operator<<(std::ostream& output, const Grid<CellType, COLS, ROWS>& g)
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
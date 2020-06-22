#ifndef GRIDCONVERTER
#define GRIDCONVERTER

#include "cell/Grid.hpp"
#include <sstream>
#include <string>

namespace GridConverter {
    template<size_t columns, size_t rows>
    static constexpr std::string gridToString(cell::Grid<columns, rows> & grid) {
        std::stringstream output;
        
        output << "+";
        for (size_t i = 0; i < columns; ++i) output << "---+";
        output << "\n";

        for (size_t row = 0; row != rows; ++row) {
            std::string mid = "|";
            std::string bottom = "+";

            for (size_t col = 0; col != columns; ++col) {
                auto & cell = grid.at(col, row);
                auto & [neighbors, linker] = grid.at(col, row);

                std::string body = "   ";
                std::string corner = cell.isLinkedToEast() and
                    cell.isEastLinkedToSouthEast() and
                    cell.isLinkedToSouth() and
                    cell.isSouthLinkedToSouthEast() ?
                    " " : "+";
                
                std::string east_boundary;
                bool isEast = (col != columns - 1 && linker.isLinkedTo(neighbors.getEast()->linker));
                east_boundary = (isEast ? " " : "|");
                mid += body + east_boundary;

                std::string south_boundary;
                bool isSouth = (row != rows - 1 && linker.isLinkedTo(neighbors.getSouth()->linker));
                south_boundary = isSouth ? "   " : "---";
                bottom += south_boundary + corner;

            }
            
            output << mid << "\n";
            output << bottom << "\n";
        }
        
        return output.str();
    }
}

#endif

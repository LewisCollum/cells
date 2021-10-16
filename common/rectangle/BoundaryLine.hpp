#ifndef RECTANGLE_BOUNDARYLINE
#define RECTANGLE_BOUNDARYLINE

#include <vector>
#include <utility>
#include "rectangle/Coordinates.hpp"

namespace rectangle {
    using LateralCoordinates = std::pair<
        rectangle::Coordinates,
        rectangle::Coordinates>;

    
    template <bool isHorizontal, bool isVertical = !isHorizontal>
    class BoundaryLine {
        rectangle::Coordinates const origin;
        int const length;
        std::vector<LateralCoordinates> boundaryLine;

    public:
        BoundaryLine(rectangle::Coordinates origin, int length) : origin{origin}, length{length} {
            makeBoundaryLine();
        }

        auto const begin() const { return boundaryLine.begin(); }
        auto const end() const { return boundaryLine.end(); }

    private:
        void makeBoundaryLine() requires isHorizontal {
            for (int i = 0; i < length; ++i) {
                LateralCoordinates coordinates = {                
                    {x: origin.x+i, y: origin.y},
                    {x: origin.x+i, y: origin.y+1}};

                boundaryLine.emplace_back(coordinates);
            }
        }
    
        void makeBoundaryLine() requires isVertical {
            for (int i = 0; i < length; ++i) {
                LateralCoordinates coordinates = {
                    {x: origin.x, y: origin.y+i},
                    {x: origin.x+1, y: origin.y+i}};
                
                boundaryLine.emplace_back(coordinates);
            }
        }
    };

    using HorizontalBoundaryLine = BoundaryLine<true>;
    using VerticalBoundaryLine = BoundaryLine<false>;

    using BoundaryLineTypes = std::variant<VerticalBoundaryLine, HorizontalBoundaryLine>;    
}
#endif

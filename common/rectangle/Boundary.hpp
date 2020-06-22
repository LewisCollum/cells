#ifndef RECTANGLE_BOUNDARY
#define RECTANGLE_BOUNDARY

#include <functional>
#include <variant>
#include "rectangle/Limits.hpp"
#include "rectangle/BoundaryLine.hpp"

namespace rectangle {
    class Boundary {
        rectangle::Limits const & limits;
        std::array<rectangle::BoundaryLineTypes, 4> const boundaryLines;

        Coordinates const westOrigin{x:limits.x.first-1, y:limits.y.first};
        Coordinates const eastOrigin{x:limits.x.second-1, y:limits.y.first};
        Coordinates const southOrigin{x:limits.x.first, y:limits.y.second-1};
        Coordinates const northOrigin{x:limits.x.first, y:limits.y.first-1};        
        
    public:    

        Boundary(rectangle::Limits const & limits) : limits{limits}, boundaryLines{
            VerticalBoundaryLine{westOrigin, limits.height()},
            VerticalBoundaryLine{eastOrigin, limits.height()},
            HorizontalBoundaryLine{southOrigin, limits.width()},
            HorizontalBoundaryLine{northOrigin, limits.width()}} {};

        //using onLateralCoordinates = std::function<void([[maybe_unused]] LateralCoordinates)>;
        void forEachLateralCoordinates(auto on) const {
            for (auto const & boundaryLine : boundaryLines)
                std::visit([&](auto visitedBoundaryLine){
                    for (auto const & lateralCoordinates: visitedBoundaryLine)
                        on(lateralCoordinates);
                }, boundaryLine);
        }
    };
}
#endif

#ifndef RECTANGLE_BOUNDARY
#define RECTANGLE_BOUNDARY

#include <functional>
#include <variant>
#include "rectangle/Limits.hpp"
#include "rectangle/BoundaryLine.hpp"

namespace rectangle {
    class Boundary {
        rectangle::Limits const & limits;

        Coordinates const westOrigin;
        Coordinates const eastOrigin;
        Coordinates const southOrigin;
        Coordinates const northOrigin;        

        std::array<rectangle::BoundaryLineTypes, 4> const boundaryLines;
        
    public:    

        Boundary(rectangle::Limits const & limits) :
            limits{limits},
            westOrigin{Coordinates{x:limits.x.first-1, y:limits.y.first}},
            eastOrigin{Coordinates{x:limits.x.second, y:limits.y.first}},
            southOrigin{Coordinates{x:limits.x.first, y:limits.y.second}},
            northOrigin{Coordinates{x:limits.x.first, y:limits.y.first-1}},
            boundaryLines{
                VerticalBoundaryLine{westOrigin, limits.height()},
                VerticalBoundaryLine{eastOrigin, limits.height()},
                HorizontalBoundaryLine{southOrigin, limits.width()},
                HorizontalBoundaryLine{northOrigin, limits.width()}} {};

        //using onLateralCoordinates = std::function<void([[maybe_unused]] LateralCoordinates)>;
        void forEachLateralCoordinates(auto on) const {
            for (auto const & boundaryLine : boundaryLines)
                std::visit([&](auto visitedBoundaryLine){
                    for (auto const & lateralCoordinates: visitedBoundaryLine) {
                        on(lateralCoordinates);
                    }
                }, boundaryLine);
        }
    };
}
#endif

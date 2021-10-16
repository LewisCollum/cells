#ifndef RECTANGLE_COORDINATES
#define RECTANGLE_COORDINATES

namespace rectangle {
    struct Coordinates {
        int x;
        int y;
        
        constexpr inline Coordinates operator-(Coordinates other) const {
            return Coordinates{x-other.x, y-other.y};
        }

        constexpr inline Coordinates operator+(Coordinates other) const {
            return Coordinates{x+other.x, y+other.y};
        }        
    };
}

#endif

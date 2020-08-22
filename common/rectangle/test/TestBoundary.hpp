#ifndef TESTBOUNDARY
#define TESTBOUNDARY

#include <cxxtest/TestSuite.h>
#include "rectangle/Boundary.hpp"

class TestBoundary : public CxxTest::TestSuite {
    rectangle::Limits const boundaryLimits{x:{1,3}, y:{1,3}};
    rectangle::Boundary const boundary{boundaryLimits};
    
public:
    void test_sizeOfLateralCoordinates() {
        auto expectedSize = 12;
        auto actualSize = 0;
        
        boundary.forEachLateralCoordinates([&](auto & coordinatePair){
            std::cout << coordinatePair.first.x << " " << coordinatePair.first.y << ", "
                      << coordinatePair.second.x << " " << coordinatePair.second.y << std::endl;
            
            ++actualSize;
        });

        TS_ASSERT_EQUALS(expectedSize, actualSize);
    }
};

#endif

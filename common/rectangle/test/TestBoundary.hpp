#ifndef TESTBOUNDARY
#define TESTBOUNDARY

#include <cxxtest/TestSuite.h>
#include "rectangle/Boundary.hpp"

class TestBoundary : public CxxTest::TestSuite {
    rectangle::Limits const boundaryLimits{x:{0,2}, y:{0,2}};
    rectangle::Boundary const boundary{boundaryLimits};
    
public:
    void test_sizeOfLateralCoordinates() {
        auto expectedSize = 12;
        auto actualSize = 0;
        
        boundary.forEachLateralCoordinates([&]([[maybe_unused]] auto){
            ++actualSize;
        });

        TS_ASSERT_EQUALS(expectedSize, actualSize);
    }
};

#endif

#ifndef TESTBOUNDARY
#define TESTBOUNDARY

#include <cxxtest/TestSuite.h>
#include "Boundary.hpp"

class TestBoundary : public CxxTest::TestSuite {
    static constexpr rectangle::Limits boundaryLimits{x:{0,2}, y:{0,2}};
    static constexpr rectangle::Boundary<boundaryLimits> boundary{};
    
public:
    void test_sizeOfLateralCoordinates() {
        auto expectedSize = 12;
        auto actualSize = 0;
        
        boundary.forEachLateralCoordinates([&](auto lateralCoordinates){
            ++actualSize;
        });

        TS_ASSERT_EQUALS(expectedSize, actualSize);
    }
};

#endif

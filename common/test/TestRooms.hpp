#ifndef TESTROOMS
#define TESTROOMS

#include <cxxtest/TestSuite.h>
#include "Rooms.hpp"

class TestRooms : public CxxTest::TestSuite {
public:
    void test_() {
        auto rooms = Rooms::generateWithinArea(2, 4, 100);
    }
};

#endif 

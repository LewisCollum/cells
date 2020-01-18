#ifndef TESTROOM
#define TESTROOM

#include <cxxtest/TestSuite.h>
#include "Room.hpp"

class TestRoom : public CxxTest::TestSuite {
    Room room{xBounds:{1, 2}, yBounds:{1, 3}};
    
public:
    void test_roomWidth() {
        size_t expected = 2;
        size_t actual = room.width();

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_roomHeight() {
        size_t expected = 3;
        size_t actual = room.height();

        TS_ASSERT_EQUALS(expected, actual);
    }

    
    void test_yIsBetweenBounds_yIsInBounds() {
        bool expected = true;
        size_t arbitraryXInBounds = room.xBounds.first;        
        bool actual = room.isWithinBounds(arbitraryXInBounds, room.yBounds.first);

        TS_ASSERT_EQUALS(expected, actual);
    }
    
    void test_yIsGreaterThanUpperYBound_yIsNotInBounds() {
        bool expected = false;
        size_t arbitraryXInBounds = room.xBounds.first;        
        bool actual = room.isWithinBounds(arbitraryXInBounds, room.yBounds.second+1);

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_yIsLessThanLowerYBound_yIsNotInBounds() {
        bool expected = false;
        size_t arbitraryXInBounds = room.xBounds.first;
        bool actual = room.isWithinBounds(arbitraryXInBounds, room.yBounds.first-1);

        TS_ASSERT_EQUALS(expected, actual);
    }    

    
    void test_xIsBetweenBounds_xIsInBounds() {
        bool expected = true;
        size_t arbitraryYInBounds = room.yBounds.first;        
        bool actual = room.isWithinBounds(room.xBounds.first, arbitraryYInBounds);

        TS_ASSERT_EQUALS(expected, actual);
    }
    
    void test_xIsGreaterThanUpperXBound_xIsNotInBounds() {
        bool expected = false;
        size_t arbitraryYInBounds = room.yBounds.first;
        bool actual = room.isWithinBounds(room.xBounds.second+1, arbitraryYInBounds);

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_xIsLessThanLowerXBound_xIsNotInBounds() {
        bool expected = false;
        size_t arbitraryYInBounds = room.yBounds.first;        
        bool actual = room.isWithinBounds(room.xBounds.first-1, arbitraryYInBounds);

        TS_ASSERT_EQUALS(expected, actual);
    }    
};

#endif

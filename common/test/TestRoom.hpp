#ifndef TESTROOM
#define TESTROOM

#include <cxxtest/TestSuite.h>
#include "Room.hpp"

class TestRoom : public CxxTest::TestSuite {
    Room room{xBounds:{0, 3}, yBounds:{0, 3}};
    
public:
    void test_roomWidth() {
        Room widthOnlyRoom{{0, 2}, {0, 0}};
        size_t expected = 3;
        size_t actual = widthOnlyRoom.width();

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_roomHeight() {
        Room heightOnlyRoom{{0, 0}, {0, 3}};        
        size_t expected = 4;
        size_t actual = heightOnlyRoom.height();

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

    void test_otherRoomIsWrapping_isOverlapping() {
        Room other{
          xBounds: {room.xBounds.first-1, room.xBounds.second+1},
          yBounds: {room.yBounds.first-1, room.yBounds.second+1}};

        bool expected = true;
        bool actual = room.isOverlappingRoom(other);

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_otherRoomIsInside_isOverlapping() {
        Room other{
          xBounds: {room.xBounds.first+1, room.xBounds.second-1},
          yBounds: {room.yBounds.first+1, room.yBounds.second-1}};

        bool expected = true;
        bool actual = room.isOverlappingRoom(other);

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_otherRoomTopLeftInside_isOverlapping() {
        Room other{
          xBounds: {room.xBounds.first+1, room.xBounds.second+1},
          yBounds: {room.yBounds.first+1, room.yBounds.second+1}};

        bool expected = true;
        bool actual = room.isOverlappingRoom(other);

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_otherRoomTopRightInside_isOverlapping() {
        Room other{
          xBounds: {room.xBounds.first-1, room.xBounds.second-1},
          yBounds: {room.yBounds.first+1, room.yBounds.second+1}};

        bool expected = true;
        bool actual = room.isOverlappingRoom(other);

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_otherRoomBottomLeftInside_isOverlapping() {
        Room other{
          xBounds: {room.xBounds.first+1, room.xBounds.second+1},
          yBounds: {room.yBounds.first-1, room.yBounds.second-1}};

        bool expected = true;
        bool actual = room.isOverlappingRoom(other);

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_otherRoomBottomRightInside_isOverlapping() {
        Room other{
          xBounds: {room.xBounds.first-1, room.xBounds.second-1},
          yBounds: {room.yBounds.first-1, room.yBounds.second-1}};

        bool expected = true;
        bool actual = room.isOverlappingRoom(other);

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_otherRoomIntersectsButNoCornersInside_isOverlapping() {
        Room other{
          xBounds: {room.xBounds.first+1, room.xBounds.second-1},
          yBounds: {room.yBounds.first-1, room.yBounds.second+1}};

        bool expected = true;
        bool actual = room.isOverlappingRoom(other);

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_otherRoomTouchingOnRight_isOverlapping() {
        Room other{
          xBounds: {room.xBounds.second, room.xBounds.second+1},
          yBounds: {room.yBounds.first-1, room.yBounds.second+1}};

        bool expected = true;
        bool actual = room.isOverlappingRoom(other);

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_otherRoomTouchingOnLeft_isOverlapping() {
        Room other{
          xBounds: {room.xBounds.first-1, room.xBounds.first},
          yBounds: {room.yBounds.first-1, room.yBounds.second+1}};

        bool expected = true;
        bool actual = room.isOverlappingRoom(other);

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_otherRoomTouchingOnTop_isOverlapping() {
        Room other{
          xBounds: {room.xBounds.first-1, room.xBounds.second+1},
          yBounds: {room.yBounds.first-1, room.yBounds.first}};

        bool expected = true;
        bool actual = room.isOverlappingRoom(other);

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_otherRoomTouchingOnBottom_isOverlapping() {
        Room other{
          xBounds: {room.xBounds.first-1, room.xBounds.first+1},
          yBounds: {room.yBounds.second, room.yBounds.second+1}};

        bool expected = true;
        bool actual = room.isOverlappingRoom(other);

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_otherRoomOnRight_isNotOverlapping() {
        Room other{
          xBounds: {room.xBounds.second+2, room.xBounds.second+3},
          yBounds: {room.yBounds.first-1, room.yBounds.second+1}};

        bool expected = false;
        bool actual = room.isOverlappingRoom(other);

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_otherRoomOnLeft_isNotOverlapping() {
        Room other{
          xBounds: {room.xBounds.first-3, room.xBounds.first-2},
          yBounds: {room.yBounds.first-1, room.yBounds.second+1}};

        bool expected = false;
        bool actual = room.isOverlappingRoom(other);

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_otherRoomOnTop_isNotOverlapping() {
        Room other{
          xBounds: {room.xBounds.first-1, room.xBounds.second+1},
          yBounds: {room.yBounds.first-3, room.yBounds.first-2}};

        bool expected = false;
        bool actual = room.isOverlappingRoom(other);

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_otherRoomOnBottom_isNotOverlapping() {
        Room other{
          xBounds: {room.xBounds.first-1, room.xBounds.first+1},
          yBounds: {room.yBounds.second+2, room.yBounds.second+3}};

        bool expected = false;
        bool actual = room.isOverlappingRoom(other);

        TS_ASSERT_EQUALS(expected, actual);
    }    
};

#endif

#ifndef TESTRANDOMSELECTOR
#define TESTRANDOMSELECTOR

#include <cxxtest/TestSuite.h>
#include <forward_list>
#include <unordered_map>
#include "RandomSelector.hpp"
#include <iostream>

class TestRandomSelector: public CxxTest::TestSuite {
    struct MockChoice{};
    MockChoice choiceA, choiceB;

public:
    void test_selectPointerFromList_returnsAValuePointer() {
        std::forward_list<MockChoice*> chooseables;
        chooseables.emplace_front(&choiceA);
        chooseables.emplace_front(&choiceB);
        
        auto choice = RandomSelector::select(chooseables);
        
        TS_ASSERT((choice == &choiceA) xor (choice == &choiceB));
    }

    void test_selectFromList_returnsAValue() {
        std::forward_list<int> chooseables;
        chooseables.emplace_front(1);
        chooseables.emplace_front(2);
        
        auto choice = RandomSelector::select(chooseables);
        
        TS_ASSERT((choice == 1) xor (choice == 2));
    }    

    void test_selectPointerFromMap_returnsAValuePointer() {
        std::unordered_map<int, MockChoice*> chooseables;
        chooseables.emplace(1, &choiceA);
        chooseables.emplace(2, &choiceB);

        auto choice = RandomSelector::select(chooseables);
        auto isChosen = (choice == &choiceA) xor (choice == &choiceB);

        TS_ASSERT(isChosen);
    }

    void test_selectFromMap_returnsAValue() {
        std::unordered_map<int, int> chooseables;
        chooseables.emplace(1, 3);
        chooseables.emplace(2, 4);

        auto choice = RandomSelector::select(chooseables);
        auto isChosen = (choice == 3) xor (choice == 4);

        TS_ASSERT(isChosen);
    }
    
    void test_selectFromEmptyPointerList_returnsNullptr() {
        std::forward_list<MockChoice*> chooseables;

        MockChoice * choice = RandomSelector::select(chooseables);
        auto isChosen = choice == nullptr;

        TS_ASSERT(isChosen);
    }    
};

#endif

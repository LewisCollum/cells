#ifndef TESTRANDOMSELECTOR
#define TESTRANDOMSELECTOR

#include <cxxtest/TestSuite.h>
#include <forward_list>
#include "RandomSelector.hpp"

struct MockChoice{};

class TestRandomSelector: public CxxTest::TestSuite {
    std::forward_list<MockChoice*> chooseables;

public:
    void test_selectFromTwoChooseables_choiceIsOneOrOther() {
        MockChoice choiceA, choiceB;
        chooseables.emplace_front(&choiceA);
        chooseables.emplace_front(&choiceB);
        
        auto choice = RandomSelector::select(chooseables);
        
        TS_ASSERT((choice == &choiceA) xor (choice == &choiceB));
    }
};

#endif

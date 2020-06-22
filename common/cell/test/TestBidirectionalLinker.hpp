#include <cxxtest/TestSuite.h>
#include "cell/Linker.hpp"

class TestBidirectionalLinker: public CxxTest::TestSuite {
    cell::BidirectionalLinker linkerA;
    cell::BidirectionalLinker linkerB;

public:    
    void test_linkerALinkToLinkerB_linkerBIsLinkedToLinkerA() {
        linkerA.link(linkerB);

        TS_ASSERT(linkerB.isLinkedTo(linkerA));
    }

    void tearDown() {
        linkerA = cell::BidirectionalLinker();
        linkerB = cell::BidirectionalLinker();
    }
};

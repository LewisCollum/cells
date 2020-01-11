#include <cxxtest/TestSuite.h>
#include "Linker.hpp"

class TestBidirectionalLinker: public CxxTest::TestSuite {
    BidirectionalLinker linkerA;
    BidirectionalLinker linkerB;

public:    
    void test_linkerALinkToLinkerB_linkerBIsLinkedToLinkerA() {
        linkerA.link(linkerB);

        TS_ASSERT(linkerB.isLinkedTo(linkerA));
    }

    void tearDown() {
        linkerA = BidirectionalLinker();
        linkerB = BidirectionalLinker();
    }
};

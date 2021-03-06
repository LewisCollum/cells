#include <cxxtest/TestSuite.h>
#include "cell/Linker.hpp"

class TestForwardLinker: public CxxTest::TestSuite {
    cell::ForwardLinker linkerA;
    cell::ForwardLinker linkerB;

public:    
    void test_linkerALinkToLinkerB_linkerAIsLinkedToLinkerB() {
        linkerA.link(linkerB);

        TS_ASSERT(linkerA.isLinkedTo(linkerB));
    }

    void test_linkerALinkToLinkerB_linkerBIsNotLinkedToLinkerA() {
        linkerA.link(linkerB);

        TS_ASSERT(!linkerB.isLinkedTo(linkerA));
    }

    void test_linkerAUnlinkFromLinkerB_linkerAIsNotLinkedToLinkerB() {
        linkerA.link(linkerB);
        linkerA.unlink(linkerB);

        TS_ASSERT(!linkerA.isLinkedTo(linkerB));
    }

    void test_linkerALinkToLinkerB_linkerAHasLinks() {
        linkerA.link(linkerB);

        TS_ASSERT(linkerA.hasLinks());
    }

    void test_defaultConstruction_linkerAHasNoLinks() {
        TS_ASSERT(!linkerA.hasLinks());
    }
    
    void tearDown() {
        linkerA = cell::ForwardLinker();
        linkerB = cell::ForwardLinker();
    }
};

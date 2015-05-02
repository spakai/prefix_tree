#include "gmock/gmock.h" 

#include "PrefixTree.h"

using namespace testing;

class PrefixTreeTest : public Test {

    public:
        PrefixTree preTree;
};

TEST_F(PrefixTreeTest, ChildrenAreNullOnCreation) {
    ASSERT_THAT(preTree.getRoot()->child[0], Eq(nullptr));
}

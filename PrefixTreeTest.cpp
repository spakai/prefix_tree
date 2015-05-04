#include "gmock/gmock.h" 

#include "PrefixTree.h"

using namespace testing;

class PrefixTreeTest : public Test {
    public:
        PrefixTree preTree;
};

TEST_F(PrefixTreeTest, ChildrenAreNullOnCreation) {
    ASSERT_THAT(preTree.getRoot()->child[5], Eq(nullptr));
}

TEST_F(PrefixTreeTest, InsertWord) {
    std::string word = "apple";
    preTree.insert(word);
    ASSERT_THAT(preTree.getRoot()->child[0]->c,Eq('a'));
}

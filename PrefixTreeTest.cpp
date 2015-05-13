#include "gmock/gmock.h" 

#include "PrefixTree.h"

using namespace testing;

class PrefixTreeTest : public Test {
    public:
        PrefixTree preTree;
        std::string apple = "apple";
        std::string ape   = "ape";
        std::string alpha = "alpha";
        std::string alphabet = "alphabet";
        std::string beta = "beta";

        Node* moveNodeTo(Node* node, int index) {
            return node->child[index];
        }

        void SetUp() override {
            preTree.insert(alpha);
            preTree.insert(apple);
            preTree.insert(ape);
        }
};

TEST_F(PrefixTreeTest, ChildrenAreNullOnCreation) {
    ASSERT_THAT(preTree.getRoot()->child[5], Eq(nullptr));
}

TEST_F(PrefixTreeTest, InsertWordThatPartlyReusesPreviousWordNode) {
    int index;
    Node* currentNode = preTree.getRoot();
    
    index = preTree.determineIndex('a');
    currentNode = moveNodeTo(currentNode, index);
    
    index = preTree.determineIndex('p');
    currentNode = moveNodeTo(currentNode, index);
 
    index = preTree.determineIndex('e');

    ASSERT_THAT(currentNode->child[index]->chr,Eq('e'));
}

TEST_F(PrefixTreeTest, SearchForAWordThatExists) {
    std::string result = preTree.search(ape);
    ASSERT_THAT(result, StrEq(ape));
}

TEST_F(PrefixTreeTest, SearchForAWordThatDoesntExist) {
    std::string result = preTree.search(beta);
    ASSERT_THAT(result, StrEq(""));
}

TEST_F(PrefixTreeTest, SearchReturnsLongestPrefixFound) {
    std::string result = preTree.search(alphabet);
    ASSERT_THAT(result, StrEq(alpha));
}

#include "gmock/gmock.h" 

#include "PrefixTree.h"

using namespace testing;

class PrefixTreeTest : public Test {
    public:
        PrefixTree preTree;
        std::string alp   = "alp";
        std::string apple = "apple";
        std::string ape   = "ape";
        std::string alpha = "alpha";
        std::string alphabet = "alphabet";
        std::string beta = "beta";

        Node* moveNodeTo(Node* node, int index) {
            return node->child[index];
        }

        void SetUp() override {
            preTree.insert(alp);
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
    auto result = preTree.search(ape);
    ASSERT_THAT(*result, StrEq(ape));
}

TEST_F(PrefixTreeTest, SearchForAWordThatDoesntExist) {
    ASSERT_THROW(preTree.search(beta), std::out_of_range);
}

TEST_F(PrefixTreeTest, SearchReturnsLongestPrefixFound) {
    auto result = preTree.search(alphabet);
    ASSERT_THAT(*result, StrEq(alpha));
}

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
};

TEST_F(PrefixTreeTest, ChildrenAreNullOnCreation) {
    ASSERT_THAT(preTree.getRoot()->child[5], Eq(nullptr));
}

TEST_F(PrefixTreeTest, DISABLED_InsertWord) {
    int index;
    preTree.insert(apple);
    Node* currentNode = preTree.getRoot();
    ASSERT_THAT(currentNode->child[0]->chr,Eq('a'));
    index = (int)('p' - 'a');
    currentNode = moveNodeTo(currentNode, 0);
    ASSERT_THAT(currentNode->child[index]->chr,Eq('p'));
    currentNode = moveNodeTo(currentNode, index);
 
    ASSERT_THAT(currentNode->child[index]->chr,Eq('p'));
    currentNode= currentNode->child[index];
    index = (int)('l' - 'a');
    ASSERT_THAT(currentNode->child[index]->chr,Eq('l'));
    currentNode= currentNode->child[index];
    index = (int)('e' - 'a');
    ASSERT_THAT(currentNode->child[index]->chr,Eq('e'));
}

TEST_F(PrefixTreeTest, InsertWordThatPartlyReusesPreviousWordNode) {
    int index;
    preTree.insert(apple);
    preTree.insert(ape);
    Node* currentNode = preTree.getRoot();
    index = preTree.determineIndex('a');
    ASSERT_THAT(currentNode->child[index]->chr,Eq('a'));
    currentNode = moveNodeTo(currentNode, index);
    
    index = preTree.determineIndex('p');
    ASSERT_THAT(currentNode->child[index]->chr,Eq('p'));
    currentNode = moveNodeTo(currentNode, index);
 
    index = preTree.determineIndex('e');
    ASSERT_THAT(currentNode->child[index]->chr,Eq('e'));
}

TEST_F(PrefixTreeTest, SearchForAWordThatExists) {
    preTree.insert(apple);
    preTree.insert(ape);
    std::string result = preTree.search(ape);
    ASSERT_THAT(result, StrEq(ape));
}

TEST_F(PrefixTreeTest, SearchForAWordThatDoesntExist) {
    preTree.insert(apple);
    preTree.insert(ape);
    std::string result = preTree.search(beta);
    ASSERT_THAT(result, StrEq(""));
}

TEST_F(PrefixTreeTest, SearchReturnsLongestPrefixFound) {
    preTree.insert(alpha);
    preTree.insert(apple);
    std::string result = preTree.search(alphabet);
    ASSERT_THAT(result, StrEq(alpha));
}

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
    int index;
    std::string word = "apple";
    preTree.insert(word);
    Node* currentNode = preTree.getRoot();
    ASSERT_THAT(currentNode->child[0]->c,Eq('a'));
    index = (int)('p' - 'a');
    currentNode= currentNode->child[0];
    ASSERT_THAT(currentNode->child[index]->c,Eq('p'));
    currentNode= currentNode->child[index];
    ASSERT_THAT(currentNode->child[index]->c,Eq('p'));
    currentNode= currentNode->child[index];
    index = (int)('l' - 'a');
    ASSERT_THAT(currentNode->child[index]->c,Eq('l'));
    currentNode= currentNode->child[index];
    index = (int)('e' - 'a');
    ASSERT_THAT(currentNode->child[index]->c,Eq('e'));
}

TEST_F(PrefixTreeTest, InsertWordThatPartlyReusesPreviousWordNode) {
    int index;
    std::string word1 = "apple";
    preTree.insert(word1);
    std::string word2 = "ape";
    preTree.insert(word2);
    Node* currentNode = preTree.getRoot();
    ASSERT_THAT(currentNode->child[0]->c,Eq('a'));
    index = (int)('p' - 'a');
    currentNode= currentNode->child[0];
    ASSERT_THAT(currentNode->child[index]->c,Eq('p'));
    currentNode= currentNode->child[index];
    index = (int)('e' - 'a');
    ASSERT_THAT(currentNode->child[index]->c,Eq('e'));
}

TEST_F(PrefixTreeTest, SearchForAWordThatExists) {
    std::string word1 = "apple";
    std::string word2 = "ape";
    preTree.insert(word1);
    preTree.insert(word2);
    std::string result = preTree.search(word2);
    ASSERT_THAT(result, StrEq("FOUND"));
}

TEST_F(PrefixTreeTest, SearchForAWordThatDoesntExist) {
    std::string word1 = "apple";
    std::string word2 = "ape";
    std::string word3 = "alpha";
    preTree.insert(word1);
    preTree.insert(word2);
    std::string result = preTree.search(word3);
    ASSERT_THAT(result, StrEq("NOT_FOUND"));
}

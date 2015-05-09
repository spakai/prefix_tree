#include "PrefixTree.h"
 
PrefixTree::PrefixTree() {
    root = new Node(26);
}

PrefixTree::~PrefixTree() {
    delete root;
}

Node* PrefixTree::getRoot() {
    return root;
}

bool PrefixTree::NodeDoesNotExist(Node* currentNode, int index) {
    if(currentNode->child[index] == nullptr) {
        return true;
    } 

    return false;
} 

void PrefixTree::CreateAndAssignValue(Node* currentNode, int index, char value) {
    currentNode->child[index] = new Node(26);
    currentNode->child[index]->c = value;
}

void PrefixTree::MoveToNode(Node* currentNode, int index) {
    currentNode = currentNode->child[index];
}

void PrefixTree::insert(std::string & word) {
    int index{0};
    Node* currentNode = root;

    for(auto it=word.begin(); it!=word.end();it++) {
        index = (int)(*it - 'a');  
        if(NodeDoesNotExist(currentNode, index)) {
            char value = (char) *it;
            CreateAndAssignValue(currentNode, index, value);
            MoveToNode(currentNode, index);
        } else {
            MoveToNode(currentNode, index);
        }      
    }

    currentNode->word=word;
}

std::string PrefixTree::search(std::string & word) {
    int index{0};
    std::string longestPrefix;
    Node* currentNode = root;
    for(auto it=word.begin(); it!=word.end();it++) {
        index = (int)(*it - 'a');  
        if(currentNode->child[index] == nullptr) {
            break;
        } else {
            currentNode = currentNode->child[index];
            longestPrefix=currentNode->word;
        }
    }
    
    return longestPrefix;
} 

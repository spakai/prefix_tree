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

bool PrefixTree::NodeDoesNotExist(Node* node) {
    if(node == nullptr) {
        return true;
    } 

    return false;
} 

Node* PrefixTree::CreateAndAssignValue(Node * node, char value) {
    node = new Node(26);
    node->c = value;
    return node;
}

void PrefixTree::insert(std::string & word) {
    int index{0};
    Node* currentNode = root;

    for(auto it=word.begin(); it!=word.end();it++) {
        index = (int)(*it - 'a');  
        if(NodeDoesNotExist(currentNode->child[index])) {
            currentNode->child[index] = CreateAndAssignValue(currentNode->child[index],*it);
            currentNode = currentNode->child[index];
        } else {
            currentNode = currentNode->child[index];
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
        if(NodeDoesNotExist(currentNode->child[index])) {
            break;
        } else {
            currentNode = currentNode->child[index];
            longestPrefix=currentNode->word;
        }
    }
    
    return longestPrefix;
} 

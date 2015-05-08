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

void PrefixTree::insert(std::string & word) {
    int index{0};
    Node* currentNode = root;

    for(auto it=word.begin(); it!=word.end();it++) {
        index = (int)(*it - 'a');  
        if(currentNode->child[index] == nullptr) {
            currentNode->child[index] = new Node(26);
            currentNode->child[index]->c = *it;
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
        if(currentNode->child[index] == nullptr) {
            break;
        } else {
            currentNode = currentNode->child[index];
            longestPrefix=currentNode->word;
        }
    }
    
    return longestPrefix;
} 

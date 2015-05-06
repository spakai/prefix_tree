#include "PrefixTree.h"
 
PrefixTree::PrefixTree() {
    root = new Node(26);
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
}

std::string PrefixTree::search(std::string & word) {
    int index{0};
    Node* currentNode = root;
    for(auto it=word.begin(); it!=word.end();it++) {
        index = (int)(*it - 'a');  
        if(currentNode->child[index] == nullptr) {
            return std::string("NOT_FOUND"); 
        } else {
            currentNode = currentNode->child[index];
        }
    }
    return std::string("FOUND");

} 

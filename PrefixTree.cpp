#include "PrefixTree.h"

PrefixTree::PrefixTree() {
    root = new Node();
    loadMapping();
}


void PrefixTree::loadMapping() {
    std::string chars="abcdefghijklmnopqrstuvwxyz";
    int i{0};
    for(auto it=chars.begin(); it != chars.end(); it++) {
        charToIndexMap.emplace(*it, i++);        
    } 
}

PrefixTree::~PrefixTree() {
    delete root;
}

Node* PrefixTree::getRoot() {
    return root;
}

int PrefixTree::determineIndex(char value) {
    auto it = charToIndexMap.find(value);
    return it == charToIndexMap.end() ? -1 : it->second;
}

bool PrefixTree::nodeDoesNotExist(Node* node) {
    if(node == nullptr) {
        return true;
    } 

    return false;
} 

Node* PrefixTree::allocateMemoryAndAssignValue(Node * node, char value) {
    node = new Node();
    node->chr = value;
    return node;
}

void PrefixTree::insert(std::string & word) {
    int index{0};
    Node* currentNode = root;
    for(char & chr : word) {
        index = determineIndex(chr);
        if(nodeDoesNotExist(currentNode->child[index])) {
            currentNode->child[index] = allocateMemoryAndAssignValue(currentNode->child[index], chr);
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
    for(char & chr : word) {
        index = determineIndex(chr);
        if(nodeDoesNotExist(currentNode->child[index])) {
            break;
        } else {
            currentNode = currentNode->child[index];

            if(! currentNode->word.empty()) {
                longestPrefix=currentNode->word;
            }
        }
    }
    
    return longestPrefix;
} 

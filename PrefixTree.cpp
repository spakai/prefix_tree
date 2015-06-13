#include "PrefixTree.h"

PrefixTree::PrefixTree() {
    root = new Node();
    loadMapping();
}

void PrefixTree::loadMapping() {
    std::string chars="abcdefghijklmnopqrstuvwxyz";
    int i{0};
    for(auto & chr : chars) {
        charToIndexMap.emplace(chr, i++);        
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
    for(auto & chr : word) {
        index = determineIndex(chr);
        if(nodeDoesNotExist(currentNode->child[index])) {
            currentNode->child[index] = allocateMemoryAndAssignValue(currentNode->child[index], chr);
            currentNode = currentNode->child[index];
        } else {
            currentNode = currentNode->child[index];
        }      
    }
    currentNode->word = std::make_shared<std::string>(word);
}

std::shared_ptr<std::string> PrefixTree::search(std::string & word) {
    int index{0};
    std::shared_ptr<std::string> longestPrefix;
    Node* currentNode = root;
    for(auto & chr : word) {
        index = determineIndex(chr);
        if(nodeDoesNotExist(currentNode->child[index])) {
            break;
        } else {
            currentNode = currentNode->child[index];
            longestPrefix=currentNode->word;
        }
    }

    if(longestPrefix != nullptr) {
        return longestPrefix;
    } else {
        throw std::out_of_range("index out of range");
    }
} 

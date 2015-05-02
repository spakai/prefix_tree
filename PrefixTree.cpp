#include "PrefixTree.h"
 
PrefixTree::PrefixTree() {
    root = new Node(26);
}

Node* PrefixTree::getRoot() {
    return root;
}

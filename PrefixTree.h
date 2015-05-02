#include <vector>

struct Node {
    char c;
    std::vector<Node*> child;

    Node(int n) {
        for(int i{0}; i < n; i++) {
            child.push_back(nullptr);
        }

    }
};


class PrefixTree {
    public:
        PrefixTree();
        Node* getRoot();
    private:
        Node *root;    
};

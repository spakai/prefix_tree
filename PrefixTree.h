#include <vector>
#include <string>

struct Node {
    char c;
    std::string word;
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
        void insert(std::string & word);
        std::string search(std::string & word);
    private:
        Node *root;    
};

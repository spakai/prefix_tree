#include <vector>
#include <string>

struct Node {
    char c;
    std::string word;
    std::vector<Node*> child;
    int numberOfNodes;
    Node(int n) {
        numberOfNodes=n;
        for(int i{0}; i < numberOfNodes; i++) {
            child.push_back(nullptr);
        }
    }

    ~Node() {
        for(int i{0}; i < numberOfNodes; i++) {
            if(child[i] != nullptr) {
                delete child[i];
            } 
        }
    }
};

class PrefixTree {
    public:
        PrefixTree();
        ~PrefixTree();
        Node* getRoot();
        void insert(std::string & word);
        std::string search(std::string & word);
    private:
        Node *root;    
};

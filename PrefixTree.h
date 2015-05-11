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
        bool isNodeAvailable(int index);
        void insert(std::string & word);
        std::string search(std::string & word);
    private:
        Node *root;   
        bool NodeDoesNotExist(Node* currentNode);
        void CreateAndAssignValue(Node* currentNode, int index, char value); 
        void MoveNode(Node* currentNode, int index);
 
};

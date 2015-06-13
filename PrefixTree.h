#include <vector>
#include <string>
#include <unordered_map>
#include <memory>
#include <exception>

struct Node {
    char chr;
    std::shared_ptr<std::string> word;
    std::vector<Node*> child;
    int numberOfNodes;

    Node(int numberOfNodes=36) : numberOfNodes(numberOfNodes){
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
        void loadMapping();
        Node* getRoot();
        void insert(std::string & word);
        std::shared_ptr<std::string> search(std::string & word);
        int determineIndex(char value);

    private:
        Node *root;   
        std::unordered_map<char, int> charToIndexMap;
        bool nodeDoesNotExist(Node* currentNode);
        Node* allocateMemoryAndAssignValue(Node * currentNode, char value); 
};

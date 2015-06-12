##Synopsis
Prefix tree is one of the most popular data structures on words.
It uses the trie data structure to search a string from a collection
of strings. Search time is O(m) where m is the length of the string
being sought.

##Motivation
I want to determine the location of a landline number with longest prefix match which can also return an exact match.
|Number | Location|
|---    |---      |
|60     |Malaysia |
|6005   |Perak    |
|60055  |Ipoh     |
|6005527|Rishah   |
|600528 |Silibin  |

##Code Design
A trie can be represented with the linked list. Here, we will represent a trie which stores the words starting with a particular character. Each node of a trie can be represented by the following structure.

```cpp
struct Node {
    char chr;
    std::string word;
    std::vector<Node*> child;
};
```
The child is an vector meant to hold the address of X possible children of the node. Each node has one character assigned to it and if it is the lastcharacter of a word, the word is assigned to the word variable.

This way, the program doesn't need to keep track of individual characters it has traversed.


}

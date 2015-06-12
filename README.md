##Synopsis
Prefix tree is one of the most popular data structures on words.
It uses the trie data structure to search a string from a collection
of strings. Search time is O(m) where m is the length of the string
being sought.

##Motivation
I want to determine the location of a landline number with longest prefix match which can also return an exact match.

|Number | Location|
|---   |---      |
|60    |Malaysia |
|605   |Perak    |
|6055  |Ipoh     |
|605527|Rishah   |
|605528|Silibin  |

So if i have a number 6055286892 and i want to know it's longest prefix match , the program should return me the location = Silibin. The number 60354545454 will give me the location Malaysia. 


##Code Design
A trie can be represented with the linked list. Here, we will represent a trie which stores the words starting with a particular character. Each node of a trie can be represented by the following structure.

```cpp
struct Node {
    char chr;
    std::string word;
    std::vector<Node*> child;
};
```
The child is an vector meant to hold the address of X possible children of the node. If we are only storing characters from 0-9 then each Node has 10 children so index 0 to 9 of the vector is defaulted to nullptr. 

Each node has one character assigned to it and if it is the last character of a word, the word is assigned to the word variable.

This way, the program doesn't need to keep track of individual characters it has traversed.




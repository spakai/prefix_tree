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



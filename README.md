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





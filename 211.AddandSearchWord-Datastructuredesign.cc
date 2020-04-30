/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)

search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

Note:
You may assume that all words are consist of lowercase letters a-z.

*/

#include"211.AddandSearchWord-Datastructuredesign.h"

int main()
{
WordDictionary w;
	w.addWord("bad");
	w.addWord("dad");
	w.addWord("mad");
	cout<<w.search("pad")<<endl;
	cout<<w.search("bad")<<endl;
	cout<<w.search(".ad")<<endl;
	cout<<w.search("b..")<<endl;
WordDictionary t;
	t.addWord("at");
	t.addWord("and");
	t.addWord("an");
	t.addWord("add");
	cout<<t.search("a")<<endl;
	return 0;
}

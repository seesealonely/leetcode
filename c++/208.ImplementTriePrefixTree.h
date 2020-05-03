/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true

Note:

    You may assume that all inputs are consist of lowercase letters a-z.
    All inputs are guaranteed to be non-empty strings.


*/

#include"head.h"

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
       Trie *node =this;
	for(int i=0;i<word.size();i++)
	{
		int index=word[i]-'a';
		if(!node->next[index])
			node->next[index]=new Trie();
		node=node->next[index];
	} 
	node->isword=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
 	Trie *node=this;       
	for(int i=0;i<word.size();i++)
	{
		int index=word[i]-'a';
		if(!node->next[index]) 
			return false;	
		node=node->next[index];
	}
	return node->isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
       Trie *node=this;
	int index;
	for(int i=0;i<prefix.size();i++)
	{
		index=prefix[i]-'a';
		if(!node->next[index])
			return false;
		node=node->next[index];
	} 
	return true;
    }
	private:
	Trie *next[26]={};
	bool isword=false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

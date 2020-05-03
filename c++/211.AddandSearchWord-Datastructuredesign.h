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

#include"head.h"

class TriNode
{
	public:
	TriNode()
	{
	word=false;
	child=vector<TriNode*> (26,NULL);
	}
	vector<TriNode *> child;
	bool word;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
	root=new TriNode();	
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
	TriNode *cur=root;
       for(int i=0;i<word.size();i++)
	{
		if(cur->child[word[i]-'a']==NULL)
		{
			cur->child[word[i]-'a']=new TriNode();
		}
		cur=cur->child[word[i]-'a'];
	} 
	cur->word=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
       return dfs(0,word,root); 
    }
	bool dfs(int i,string &w,TriNode *r)
	{
		if(i==w.size()&&r->word) 
			if(r->word)
			return w.substr(i).empty();
			else 
			return false;
			if(w[i]!='.')
			return r->child[w[i]-'a']&&dfs(i+1,w,r->child[w[i]-'a']);
			else
			for(int j=0;j<26;j++)
			if(r->child[j])
			if(dfs(i+1,w,r->child[j]))
				return true;
		return false;
	}
	TriNode *root;
};

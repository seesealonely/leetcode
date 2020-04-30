/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]

 

Note:

    All inputs are consist of lowercase letters a-z.
    The values of words are distinct.

*/

#define c11
#include"head.h"

class TriNode
{
	public:
	TriNode *getRoot()
	{
		return root;
	}
	void	buildTriNode(string s)
	{
		TriNode*cur=root;
		for(int i=0;i<s.size();i++)
		{
			int index=s[i]-'a';
			if(cur->child[index]==NULL)
			cur->child[index]=new TriNode();
			cur=cur->child[index];
		}
		cur->isstring=true;
	}
	TriNode(vector<string> vs)
	{
		root=new TriNode();
		for(int i=0;i<vs.size();i++)
			buildTriNode(vs[i]);
	}
	TriNode()
	{
		child=vector<TriNode*>(26,NULL);
		isstring=false;
	}
	vector<	TriNode *> child;
	bool  isstring;
private:
	TriNode *root;
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	TriNode *r=new TriNode(words);
	unordered_set<string> res;
	vector<string> s;
	for(int i=0;i<board.size();i++)
		for(int j=0;j<board[0].size();j++)
	dfs(board,i,j,r->getRoot(),"",res);        
	for(unordered_set<string>::iterator it=res.begin();it!=res.end();it++)
	s.push_back(*it);	
	return s;
    }
	void dfs(vector<vector<char> > &board,int i,int j,TriNode *r,string w,unordered_set<string> &res)
	{
		if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]=='@'||r->child[board[i][j]-'a']==NULL)
		return ;
		char c=board[i][j];
		w+=c;
		r=r->child[c-'a'];
		if(r->isstring)
			res.insert(w);
		board[i][j]='@';
		dfs(board,i+1,j,r,w,res);
		dfs(board,i-1,j,r,w,res);
		dfs(board,i,j+1,r,w,res);
		dfs(board,i,j-1,r,w,res);
		board[i][j]=c;
	}
};

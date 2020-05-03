/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

*/

#include"head.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board,string word) {
	row=board.size();
	col=board[0].size();
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			if(dfs(board,word.c_str(),i,j)) 
			return true; 
	return false;
    }
bool dfs(vector<vector<char> >& board,const char * word,int x,int y) 
{
	if(x<0||y<0||x>=row||y>=col||*word!=board[x][y]||board[x][y]=='\0')
		return false;
	if(*(word+1)=='\0')
		 return true;
	char temp=board[x][y];
	board[x][y]='\0';
	if(dfs(board,word+1,x+1,y)||dfs(board,word+1,x-1,y)||dfs(board,word+1,x,y+1)||dfs(board,word+1,x,y-1))
	return true;
	board[x][y]=temp;
	return false;
}
private:
	int row;
	int col;
};

/*
   Write a program to solve a Sudoku puzzle by filling the empty cells.

   A sudoku solution must satisfy all of the following rules:

   Each of the digits 1-9 must occur exactly once in each row.
   Each of the digits 1-9 must occur exactly once in each column.
   Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

   Empty cells are indicated by the character '.'.


   A sudoku puzzle...


   ...and its solution numbers marked in red.

Note:

The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.
*/

#include"head.h"
class Solution {
	public:
		void solveSudoku(vector<vector<char> > & board) {
			dfs(board,0,0);
		}
		bool dfs(vector<vector<char> > & board,int r,int c) {
			if(r==9) return true;
			if(c==9) return dfs(board,r+1,0);
			if(board[r][c]!='.') return dfs(board,r,c+1); 
			for(char ch='1';ch<='9';ch++)
			{
				if(cell(board,r,c,ch)) 
				{
					board[r][c]=ch;
					if(dfs(board,r,c+1))	return true;
					board[r][c]='.';
				}
			}
			return false;
		}
		bool cell(vector<vector<char> > &board,int r,int c,char cur)
		{
			for(int i=0;i<9;i++)
				if(board[r][i]==cur||board[i][c]==cur)	 return false;
			r=r-r%3,c=c-c%3;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(board[r+i][c+j]==cur)
						return false;	
			return true;
		}
};

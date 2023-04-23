/*
   Let's play the minesweeper game (Wikipedia, online game)!

   You are given an m x n char matrix board representing the game board where:

   'M' represents an unrevealed mine,
   'E' represents an unrevealed empty square,
   'B' represents a revealed blank square that has no adjacent mines (i.e., above, below, left, right, and all 4 diagonals),
   digit ('1' to '8') represents how many mines are adjacent to this revealed square, and
   'X' represents a revealed mine.

   You are also given an integer array click where click = [clickr, clickc] represents the next click position among all the unrevealed squares ('M' or 'E').

   Return the board after revealing this position according to the following rules:

   If a mine 'M' is revealed, then the game is over. You should change it to 'X'.
   If an empty square 'E' with no adjacent mines is revealed, then change it to a revealed blank 'B' and all of its adjacent unrevealed squares should be revealed recursively.
   If an empty square 'E' with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
   Return the board when no more squares will be revealed.



   Example 1:

Input: board = [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]], click = [3,0]
Output: [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]

Example 2:

Input: board = [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]], click = [1,2]
Output: [["B","1","E","1","B"],["B","1","X","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]



Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 50
board[i][j] is either 'M', 'E', 'B', or a digit from '1' to '8'.
click.length == 2
0 <= clickr < m
0 <= clickc < n
board[clickr][clickc] is either 'M' or 'E'.

*/


#include"head.h"
class Solution {
	public:
		int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
		int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
		int r, c;
		vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		r=board.size(),c=board[0].size();
		vector<vector<bool>> vis(r,vector<bool>(c,false));

		dfs(board,vis,click[0],click[1]);

		return board;
		}
		bool dfs(vector<vector<char>> &board,vector<vector<bool>>&vis,int x,int y)
		{
			vis[x][y]=true;
			if(board[x][y]=='M')
			{
				board[x][y]='X';
				return true;
			}

			int cnt=0;
			for(int i=0;i<8;i++)
			{
				int x1=x+dx[i],y1=y+dy[i];
				if(x1<0||x1>=r||y1<0||y1>=c) continue;
				if(board[x1][y1]=='M')
					cnt++;
			}

			if(cnt!=0)
				board[x][y]=cnt+'0';
			else
			{
				board[x][y]='B';
				for(int i=0;i<8;i++)
				{
					int x1=x+dx[i],y1=y+dy[i];
					if(x1<0||y1<0||x1>=r||y1>=c||vis[x1][y1]) continue;
					if(dfs(board,vis,x1,y1)) return true;
				}
			}
			return false;
		}
};


int main() 
{
	Solution s;
	vector<vector<char>> b={{'E','E','E','E','E'},{'E','E','M','E','E'},{'E','E','E','E','E'},{'E','E','E','E','E'}};
	vector<int> c={3,0};
	show(s.updateBoard(b,c));
	return 0;
}

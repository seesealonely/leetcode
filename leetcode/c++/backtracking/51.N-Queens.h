/*
   The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

   Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

   Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.



   Example 1:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:

Input: n = 1
Output: [["Q"]]



Constraints:

1 <= n <= 9


*/
#include"head.h"
class Solution {
	public:
		vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;
		vector<string> s(n,string(n,'.'));
		dfs(n,0,s,res);
		return res;
		}
		void dfs(int n,int curRow,vector<string> &s,vector<vector<string>> &res)
		{
			if(curRow==n)
			{
				res.push_back(s);
				return ;
			}			
			for(int i=0;i<n;i++)
			{
				if(check(curRow,i,s))
				{
					s[curRow][i]='Q';
					dfs(n,curRow+1,s,res);
					s[curRow][i]='.';
				}
			}
		}
		bool check(int r,int c,vector<string> &s)
		{
			for(int i=0;i<s.size();i++)
				if(s[i][c]=='Q')
					return false;
			for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--)
				if(s[i][j]=='Q')
					return false;
			for(int i=r-1,j=c+1;i>=0&&j<s.size();i--,j++)
				if(s[i][j]=='Q')
					return false;
			return true;
		}
};

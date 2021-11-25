/*
   The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

   Given an integer n, return the number of distinct solutions to the n-queens puzzle.



   Example 1:

Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

Example 2:

Input: n = 1
Output: 1



Constraints:

1 <= n <= 9

*/
#include"head.h"
class Solution {
	public:
		int totalNQueens(int n) {
		vector<bool> col(n,false),diag(2*n,false),adiag(2*n,false);
		int res=0;
		dfs(res,0,col,diag,adiag);
		return res;
		}
		void dfs(int &res,int r,vector<bool> &c,vector<bool> &d,vector<bool> &ad)
		{
			if(r==c.size())
			{
				res++;
				return;
			}
			for(int i=0;i<c.size();i++)
			{
				int d1=r-i+c.size(),d2=r+i;
				if(c[i]||d[d1]||ad[d2]) 
					 continue;
				c[i]=d[d1]=ad[d2]=true;
				dfs(res,r+1,c,d,ad);
				c[i]=d[d1]=ad[d2]=false;
			}
		}

};

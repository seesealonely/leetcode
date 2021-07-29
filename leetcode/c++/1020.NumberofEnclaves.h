/*
   You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

   A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

   Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.



   Example 1:

Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

Example 2:

Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.



Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.

*/
#include"head.h"
class Solution {
	public:
		int numEnclaves(vector<vector<int>>& grid) {
			return dfs(grid);
		}
		int dfs(vector<vector<int> > &grid)
		{
			int res=0;
			for(int i=0;i<grid.size();i++)
				for(int j=0;j<grid[0].size();j++)
					if(i*j==0||i==grid.size()-1||j==grid[0].size()-1)
						filpZero(grid,i,j);
			for(int i=0;i<grid.size();i++)
				for(int j=0;j<grid[0].size();j++)
					if(grid[i][j])
					res++;
			return res;
		}
		void filpZero(vector<vector<int> > &v,int x,int y)
		{
			if(0<=x&&x<v.size()&&0<=y&&y<v[0].size()&&v[x][y])
			{
				vector<vector<int> > dir={{-1,0},{1,0},{0,-1},{0,1}};
				v[x][y]=0;
				for(int i=0;i<4;i++)
					filpZero(v,x+dir[i][0],y+dir[i][1]);
			}
		}
};

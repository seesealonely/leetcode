/*
   You are given an m x n integer matrix grid, and three integers row, col, and color. Each value in the grid represents the color of the grid square at that location.

   Two squares belong to the same connected component if they have the same color and are next to each other in any of the 4 directions.

   The border of a connected component is all the squares in the connected component that are either 4-directionally adjacent to a square not in the component, or on the boundary of the grid (the first or last row or column).

   You should color the border of the connected component that contains the square grid[row][col] with color.

   Return the final grid.



   Example 1:

Input: grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
Output: [[3,3],[3,2]]

Example 2:

Input: grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
Output: [[1,3,3],[2,3,3]]

Example 3:

Input: grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
Output: [[2,2,2],[2,1,2],[2,2,2]]



Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j], color <= 1000
0 <= row < m
0 <= col < n

*/


#include"head.h"
static const vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
class Solution {
	public:
		int r,c;
		void dfs(int x,int y,int color,const vector<vector<int>> &g,vector<vector<int>>& vis)
		{
			vis[x][y]=0;
			for(int i=0;i<4;i++)
			{
				int cx=x+dirs[i][0],cy=y+dirs[i][1];
				if(cx<0||cx>=r||cy<0||cy>=c||g[cx][cy]!=g[x][y])
				{
					vis[x][y]=color;
					continue;
				}

				if(vis[cx][cy]==-1)
					dfs(cx,cy,color,g,vis);
			}
		}
		vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
		r=grid.size(),c=grid.front().size();

		vector<vector<int>> vis(r,vector<int>(c,-1));

		dfs(row,col,color,grid,vis);
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if(vis[i][j]>0)
					grid[i][j]=vis[i][j];

		return grid;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> grid={{1,1},{1,2}};
	show(s.colorBorder(grid,0,0,3));
	grid.clear();grid={{1,2,2},{2,3,2}};
	show(s.colorBorder(grid,0,1,3));
	grid.clear();grid={{1,1,1},{1,1,1},{1,1,1}};
	show(s.colorBorder(grid,1,1,2));
	return 0;
}

/*
   You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

   A land cell if grid[r][c] = 0, or
   A water cell containing grid[r][c] fish, if grid[r][c] > 0.

   A fisher can start at any water cell (r, c) and can do the following operations any number of times:

   Catch all the fish at cell (r, c), or
   Move to any adjacent water cell.

   Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.

   An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.



   Example 1:

Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
Output: 7
Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.

Example 2:

Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
Output: 1
Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish.



Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
0 <= grid[i][j] <= 10

*/


#include"head.h"
class Solution {
	public:
		int findMaxFish(vector<vector<int>>& grid) {
		const int r=grid.size(),c=grid.front().size();

		int res=0;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if(grid[i][j])
					res=max(res,dfs(grid,i,j,r,c));
		return res;
		}
		int dfs(vector<vector<int>> &g,int x,int y,int r,int c)
		{
			if(x<0||y<0||x>=r||y>=c||g[x][y]==0)
				return 0;
			int fish=g[x][y];
			g[x][y]=0;
			return fish+dfs(g,x+1,y,r,c)+dfs(g,x-1,y,r,c)+dfs(g,x,y+1,r,c)+dfs(g,x,y-1,r,c);
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> v={{0,2,1,0},{4,0,0,3},{1,0,0,4},{0,3,2,0}};
	cout<<s.findMaxFish(v)<<endl;
	v.clear();v={{1,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,1}};
	cout<<s.findMaxFish(v)<<endl;
	return 0;
}

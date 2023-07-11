/*
   You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.

   The grid is said to be connected if we have exactly one island, otherwise is said disconnected.

   In one day, we are allowed to change any single land cell (1) into a water cell (0).

   Return the minimum number of days to disconnect the grid.



   Example 1:

Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]

Output: 2
Explanation: We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.

Example 2:

Input: grid = [[1,1]]
Output: 2
Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.



Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 30
grid[i][j] is either 0 or 1.

*/


#include"head.h"
class Solution {
	public:
		int m,n,ts;
		vector<vector<int>> dfn,low;
		bool cut;
		int rx,ry;
		void dfs(int x,int y,const vector<vector<int>>&grid)
		{
			const int dx[4]={0,1,0,-1};
			const int dy[4]={1,0,-1,0};

			dfn[x][y]=low[x][y]=++ts;
			int branch=0;
			for(int i=0;i<4;i++)
			{
				int tx=x+dx[i],ty=y+dy[i];
				if(tx<0||ty<0||tx>=m||ty>=n||grid[tx][ty]==0)
					continue;

				if(dfn[tx][ty])
				{
					low[x][y]=min(low[x][y],dfn[tx][ty]);
					continue;
				}

				dfs(tx,ty,grid);
				branch++;
				low[x][y]=min(low[x][y],low[tx][ty]);
				if(low[tx][ty]>=dfn[x][y])
					if(branch>=2||!(x==rx&&y==ry))
						cut=true;
			}
		}
		int minDays(vector<vector<int>>& grid) {
			m=grid.size();
			n=grid[0].size();
			dfn.resize(m,vector<int>(n,0));
			low.resize(m,vector<int>(n,0));

			ts=0;
			cut=false;

			bool first=false;
			for(int i=0;i<m;i++)
				for(int j=0;j<n;j++)
					if(grid[i][j]==1&&dfn[i][j]==0)
					{
						if(first) return 0;
						first=true;
						rx=i,ry=j;
						dfs(i,j,grid);
					}

			if(!first) return 0;
			if(ts==1||cut) return 1;
			return 2;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>>  grid = {{0,1,1,0},{0,1,1,0},{0,0,0,0}};
	cout<<s.minDays(grid)<<endl;
	grid.clear();grid={{1,1}};
	cout<<s.minDays(grid)<<endl;
	return 0;
}

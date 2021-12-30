/*
   You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

   The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

   Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).



   Example 1:

Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.

Example 2:

Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.



Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 50
0 <= grid[i][j] < n2
Each value grid[i][j] is unique.

*/
#include"head.h"
class Solution {
	public:
		int swimInWater(vector<vector<int>>& grid) {
		const int n=grid.size();
		if(n==1) return 0;
		int l=0,r=n*n;
		vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
		while(l<r)
		{
			vector<vector<bool> > visit(n,vector<bool>(n,false));
			const int m=(l+r)>>1;
			if(grid[0][0]<=m&&dfs(visit,grid,dir,0,0,n,m))
					r=m;
			else
				l=m+1;
		}		
		return r;
		}
		bool dfs(vector<vector<bool> > &vis,vector<vector<int> > &g,vector<vector<int> > &dir,int x,int y,int n,int level)
		{
			vis[x][y]=true;
			for(int i=0;i<4;i++)
			{
				int xx=x+dir[i][0],yy=y+dir[i][1];
				if(xx>=0&&xx<n&&yy>=0&&yy<n&&!vis[xx][yy]&&g[xx][yy]<=level)
				{
					if(xx==n-1&&yy==n-1)
						return true;
					if(dfs(vis,g,dir,xx,yy,n,level))
						return true;
				}
			}	
			return false;
		}
};
int main() 
{
	Solution s;
	vector<vector<int> > v={{0,2},{1,3}};
	cout<<s.swimInWater(v)<<endl;
	v.clear();v={{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
	cout<<s.swimInWater(v)<<endl;
	return 0;
}

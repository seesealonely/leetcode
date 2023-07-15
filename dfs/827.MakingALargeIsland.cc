/*
   You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

   Return the size of the largest island in grid after applying this operation.

   An island is a 4-directionally connected group of 1s.



   Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.



Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.
*/

#define c11
#include"head.h"
class Solution {
	public:
		const int dx[4]={0,1,0,-1};
		const int dy[4]={1,0,-1,0};
		void dfs(int x,int y,int r,int c,const vector<vector<int>> &grid,int &size,int idx,vector<vector<int>> &vis)
		{
			vis[x][y]=idx;
			size++;
			for(int i=0;i<4;i++)
			{
				int tx=x+dx[i],ty=y+dy[i];
				if(tx<0||ty<0||tx>=r||ty>=c||grid[tx][ty]==0||vis[tx][ty]!=-1)
					continue;
				dfs(tx,ty,r,c,grid,size,idx,vis);
			}
		}
		int largestIsland(vector<vector<int>>& grid) {
		int r=grid.size(),c=grid[0].size();
		vector<int> size(r*c,0);
		vector<vector<int>> vis(r,vector<int>(c,-1));

		int idx=0,res=0;

		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if(grid[i][j]==1&&vis[i][j]==-1)
				{
					dfs(i,j,r,c,grid,size[idx],idx,vis);
					res=max(res,size[idx]);
					idx++;
				}

		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if(grid[i][j]==0)
				{
					unordered_set<int> islands;
					for(int m=0;m<4;m++)
					{
						int tx=i+dx[m],ty=j+dy[m];
						if(tx<0||ty<0||tx>=r||ty>=c||grid[tx][ty]==0)
							continue;
						islands.insert(vis[tx][ty]);
					}
					int tot=1;
					for(unordered_set<int>::iterator it=islands.begin();it!=islands.end();it++)
						tot+=size[*it];
					res=max(res,tot);
				}
		return res;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> grid={{1,0},{0,1}};
	cout<<s.largestIsland(grid)<<endl;
	grid.clear();grid={{1,1},{1,0}};
	cout<<s.largestIsland(grid)<<endl;
	grid.clear();grid={{1,1},{1,1}};
	cout<<s.largestIsland(grid)<<endl;
	return 0;
}

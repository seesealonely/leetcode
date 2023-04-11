/*
   You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

   An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

   You may change 0's to 1's to connect the two islands to form one island.

   Return the smallest number of 0's you must flip to connect the two islands.



   Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1

Example 2:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2

Example 3:

Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1



Constraints:

n == grid.length == grid[i].length
2 <= n <= 100
grid[i][j] is either 0 or 1.
There are exactly two islands in grid.

*/


#include"head.h"
class Solution {
	public:
		int dx[4]={0,1,0,-1};
		int dy[4]={1,0,-1,0};
		int shortestBridge(vector<vector<int>>& grid) {
			int r=grid.size(),c=grid.front().size();
			queue<pair<int,int>> q;
			vector<vector<int>> dis(r,vector<int>(c,r*c));
			bool  flag=false;

			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
					if(grid[i][j])
					{
						dfs(i,j,r,c,q,grid,dis);
						flag=true;
						break;
					}
				if(flag)
					break;
			}

			while(!q.empty())
			{
				int x=q.front().first,y=q.front().second;
				q.pop();
				for(int i=0;i<4;i++)
				{
					int cx=x+dx[i],cy=y+dy[i];
					if(cx>=0&&cx<r&&cy>=0&&cy<r&&dis[cx][cy]>dis[x][y]+1)
					{
						dis[cx][cy]=dis[x][y]+1;
						q.push({cx,cy});
					}
				}
			}

			int res=r*c;
			for(int i=0;i<r;i++)
				for(int j=0;j<c;j++)
					if(grid[i][j])
						res=min(res,dis[i][j]-1);

			return res;
		}
		void dfs(int x,int y,int r,int c,queue<pair<int,int>> &q,vector<vector<int>>&g,vector<vector<int>>&dis)
		{
			g[x][y]=0;
			dis[x][y]=0;
			q.push({x,y});
			for(int i=0;i<4;i++)
			{
				int cx=x+dx[i],cy=y+dy[i];
				if(cx<r&&cx>=0&&cy<c&&cy>=0&&g[cx][cy])
					dfs(cx,cy,r,c,q,g,dis);
			}
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> v={{0,1},{1,0}};
	cout<<s.shortestBridge(v)<<endl;
	v.clear();v={{0,1,0},{0,0,0},{0,0,1}};
	cout<<s.shortestBridge(v)<<endl;
	v.clear();v={{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
	cout<<s.shortestBridge(v)<<endl;
	return 0;
}

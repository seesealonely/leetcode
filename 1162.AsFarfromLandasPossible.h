/*
   Given an N x N grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized and return the distance.

   The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

   If no land or water exists in the grid, return -1.



   Example 1:

Input: [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: 
The cell (1, 1) is as far as possible from all the land with distance 2.

Example 2:

Input: [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: 
The cell (2, 2) is as far as possible from all the land with distance 4.



Note:

1 <= grid.length == grid[0].length <= 100
grid[i][j] is 0 or 1

*/

#include"head.h"

class Solution {
	public:
		int maxDistance(vector<vector<int>>& grid) {
			int res=-1;
			if(grid.empty()||!grid[0].size()) return res;
			queue<pair<int,int> > q;
			int dirs[4][2]={{0,1},{1,0},{0,-1},{-1,0}}; 
			int mr=grid.size(),mc=grid[0].size();
			vector<vector<bool> > visit(mr,vector<bool>(mc,false));
			for(int i=0;i<mr;i++)
				for(int j=0;j<mc;j++)
					if(grid[i][j])
					{
						q.push({i,j});
						visit[i][j]=true;	
					}
			while(!q.empty())
			{
				int msize=q.size();
				for(int k=0;k<msize;k++)
				{
					pair<int,int> cur=q.front();q.pop();
					for(int i=0;i<4;i++)
					{
						int x=cur.first+dirs[i][0];
						int y=cur.second+dirs[i][1];
						if(boundary(grid,x,y)&&!visit[x][y]&&!grid[x][y])
						{
							q.push({x,y});
							visit[x][y]=true;
						}
					}
				}
				res++;
			}
			return res<=0?-1:res;
		}
		bool boundary(vector<vector<int>>& grid,int r,int c) {
			return r>=0&&r<grid.size()&&c>=0&&c<grid[0].size(); 
		}
};

/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]

Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally. 
Example 2:

[[0,0,0,0,0,0,0,0]]

Given the above grid, return 0.

Note: The length of each dimension in the given grid does not exceed 50. 
*/

#include"head.h"

int area(vector<vector<int> >& grid,vector<vector<int> >  &visit,int r,int c) {
	if(r<0||c<0||r>=grid.size()||c>=grid[0].size()||visit[r][c]||!grid[r][c])
		return 0;
	visit[r][c]=true;
		return	1+area(grid,visit,r+1,c)+area(grid,visit,r-1,c)+area(grid,visit,r,c+1)+area(grid,visit,r,c-1);
}
int dfs(vector<vector<int> >& grid) 
{
	if(grid.empty()) return 0;
	vector<vector<int> > v(grid.size(),vector<int>(grid[0].size(),false));
	int res=0;
	for(int i=0;i<grid.size();i++)
	for(int j=0;j<grid[i].size();j++)
	if(grid[i][j])
	res=max(res,area(grid,v,i,j));
	return res;
}
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int> >& grid) {
	return dfs(grid);	
    }
};

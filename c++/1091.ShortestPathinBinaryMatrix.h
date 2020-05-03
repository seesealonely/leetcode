/*
In an N by N square grid, each cell is either empty (0) or blocked (1).

A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:

    Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
    C_1 is at location (0, 0) (ie. has value grid[0][0])
    C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
    If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).

Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.

 

Example 1:

Input: [[0,1],[1,0]]
Output: 2

Example 2:

Input: [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

 

Note:

    1 <= grid.length == grid[0].length <= 100
    grid[r][c] is 0 or 1

*/

#include"head.h"

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
	const int row=grid.size();const int col=grid[0].size();
	if(grid[0][0]||grid[row-1][col-1])
		return -1; 
	int res=0;
	vector<vector<bool> > visit(row,vector<bool>(col,false));
	int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
	queue<pair<int,int> > qu;
	qu.push(make_pair(0,0));
	while(!qu.empty())
	{
		int curSize=qu.size();
		for(int k=0;k<curSize;k++)
		{
		pair<int,int> inQu=qu.front();qu.pop();
		int x=inQu.first;
		int y=inQu.second;
		visit[x][y]=true;
		if(x==row-1&&y==col-1)
			return res+1;
			for(int j=0;j<8;j++)
			if(direction(x+dir[j][0],y+dir[j][1],row-1,col-1)&&!grid[x+dir[j][0]][y+dir[j][1]]&&(!visit[x+dir[j][0]][y+dir[j][1]]))
			qu.push(make_pair(x+dir[j][0],y+dir[j][1]));
		}
		res++;
	}
	return -1;
    }
	bool direction(int x,int y,int maxX,int maxY)
	{
		bool res=0<=x&&x<=maxX&&0<=y&&y<=maxY;	
		return res;
	}
};

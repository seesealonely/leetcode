/*
   You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

   If isWater[i][j] == 0, cell (i, j) is a land cell.
   If isWater[i][j] == 1, cell (i, j) is a water cell.

   You must assign each cell a height in a way that follows these rules:

   The height of each cell must be non-negative.
   If the cell is a water cell, its height must be 0.
   Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).

   Find an assignment of heights such that the maximum height in the matrix is maximized.

   Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.



   Example 1:

Input: isWater = [[0,1],[0,0]]
Output: [[1,0],[2,1]]
Explanation: The image shows the assigned heights of each cell.
The blue cell is the water cell, and the green cells are the land cells.

Example 2:

Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
Output: [[1,1,0],[0,1,1],[1,2,2]]
Explanation: A height of 2 is the maximum possible height of any assignment.
Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.



Constraints:

m == isWater.length
n == isWater[i].length
1 <= m, n <= 1000
isWater[i][j] is 0 or 1.
There is at least one water cell.

*/
#include"head.h"
class Solution {
	public:
		vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
			const int r=isWater.size(),c=isWater[0].size();
			int all=r*c;

			queue<pair<int,int>> q;
			for(int i=0;i<r;i++)
				for(int j=0;j<c;j++)
					if(isWater[i][j])
						q.push({i,j});
					else
						isWater[i][j]=INT_MIN;

			vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
			int level=0;
			while(!q.empty())
			{
				int cursize=q.size();
				for(int i=0;i<cursize;i++)
				{
					int x=q.front().first,y=q.front().second;q.pop();
					isWater[x][y]=level;
					for(int i=0;i<4;i++)
					{
						int xx=x+dir[i][0],yy=y+dir[i][1];
						if(xx<0||yy<0||xx>=r||yy>=c||isWater[xx][yy]!=INT_MIN) continue;
						q.push({xx,yy});
						isWater[xx][yy]=level+1;
					}
					if(all--==0) return isWater;
				}
				level++;
			}
			return isWater;
		}
};
int main() 
{
	Solution s;
	vector<vector<int>> v={{0,1},{0,0}};
	show(s.highestPeak(v));
	v.clear();v={{0,0,1},{1,0,0},{0,0,0}};
	show(s.highestPeak(v));
	return 0;
}

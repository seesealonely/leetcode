/*
   You are given a 0-indexed m x n integer matrix grid. Your initial position is at the top-left cell (0, 0).

   Starting from the cell (i, j), you can move to one of the following cells:

   Cells (i, k) with j < k <= grid[i][j] + j (rightward movement), or
   Cells (k, j) with i < k <= grid[i][j] + i (downward movement).

   Return the minimum number of cells you need to visit to reach the bottom-right cell (m - 1, n - 1). If there is no valid path, return -1.



   Example 1:

Input: grid = [[3,4,2,1],[4,2,3,1],[2,1,0,0],[2,4,0,0]]
Output: 4
Explanation: The image above shows one of the paths that visits exactly 4 cells.

Example 2:

Input: grid = [[3,4,2,1],[4,2,1,1],[2,1,1,0],[3,4,1,0]]
Output: 3
Explanation: The image above shows one of the paths that visits exactly 3 cells.

Example 3:

Input: grid = [[2,1,0],[1,0,0]]
Output: -1
Explanation: It can be proven that no path exists.



Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 105
1 <= m * n <= 105
0 <= grid[i][j] < m * n
grid[m - 1][n - 1] == 0

*/


#include"head.h"
class Solution {
	public:
		int minimumVisitedCells(vector<vector<int>>& grid) {
		const int r=grid.size(),c=grid[0].size();

		vector<vector<bool>> vis(r,vector<bool>(c,false));

		queue<pair<int,int>> q;
		q.push({0,0});
		vis[0][0]=true;
		int step=1;
		while(true)
		{
			int size=q.size();

			if(size==0) break;
			for(int i=0;i<size;i++)
			{
				int x=q.front().first,y=q.front().second;
				q.pop();
				int add=grid[x][y];
				if(x==r-1&&y==c-1)
					return step;

				for(int j=min(r-1,x+add);j>x;j--)
				{
					if(!vis[j][y])
					{
						vis[j][y]=true;
						q.push({j,y});
					}
				}

				for(int j=min(c-1,y+add);j>y;j--)
				{
					if(!vis[x][j])
					{
						vis[x][j]=true;
						q.push({x,j});
					}
				}
			}
			step++;
		}
		return -1;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> v={{3,4,2,1},{4,2,3,1},{2,1,0,0},{2,4,0,0}};
	cout<<s.minimumVisitedCells(v)<<endl;
	v.clear();v={{3,4,2,1},{4,2,1,1},{2,1,1,0},{3,4,1,0}};
	cout<<s.minimumVisitedCells(v)<<endl;
	v.clear();v={{2,1,0},{1,0,0}};
	cout<<s.minimumVisitedCells(v)<<endl;
	return 0;
}

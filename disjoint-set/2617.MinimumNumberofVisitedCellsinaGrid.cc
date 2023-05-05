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
		int find(vector<int> &p,int x)
		{
			return p[x]==x?p[x]:p[x]=find(p,p[x]);
		}
		int minimumVisitedCells(vector<vector<int>>& grid) {
			const int r=grid.size(),c=grid[0].size();
			vector<vector<int>> row(r+1,vector<int>(c+1));
			vector<vector<int>> col(c+1,vector<int>(r+1));

			for(int i=0;i<=r;i++)
				for(int j=0;j<=c;j++)
				{
					row[i][j]=j;
					col[j][i]=i;
				}

			row[0][0]=col[0][0]=1;

			queue<pair<int,int>> q;
			q.push({0,0});

			vector<vector<int>> d(r,vector<int>(c,-1));
			d[0][0]=1;

			while(!q.empty())
			{
				pair<int,int> u=q.front();
				q.pop();
				int x=u.first,y=u.second;
				for(int j=find(row[x],y+1);j<c&&j<=y+grid[x][y];j=find(row[x],j+1))
				{
					if(d[x][j]==-1)
					{
						d[x][j]=d[x][y]+1;
						q.push({x,j});
					}
					row[x][j]=find(row[x],j+1);
				}

				for(int i=find(col[y],x+1);i<r&&i<=x+grid[x][y];i=find(col[y],i+1))
				{
					if(d[i][y]==-1)
					{
						d[i][y]=d[x][y]+1;
						q.push({i,y});
					}
					col[y][i]=find(col[y],i+1);
				}
			}
			return d[r-1][c-1];
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

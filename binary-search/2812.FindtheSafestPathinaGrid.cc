/*
   You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:

   A cell containing a thief if grid[r][c] = 1
   An empty cell if grid[r][c] = 0

   You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.

   The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.

   Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).

   An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.

   The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.



   Example 1:

Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
Output: 0
Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in cells (0, 0) and (n - 1, n - 1).

Example 2:

Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 2) is cell (0, 0). The distance between them is | 0 - 0 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.

Example 3:

Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 3) is cell (1, 2). The distance between them is | 0 - 1 | + | 3 - 2 | = 2.
- The closest cell of the path to the thief at cell (3, 0) is cell (3, 2). The distance between them is | 3 - 3 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.



Constraints:

1 <= grid.length == n <= 400
grid[i].length == n
grid[i][j] is either 0 or 1.
There is at least one thief in the grid.

*/


#include"head.h"
class Solution {
	public:
		const int dx[4]={0,1,0,-1};
		const int dy[4]={1,0,-1,0};
		static const int N=410;
		int n,d[N][N];
		bool v[N][N];
		queue<int> q;
		void init(const vector<vector<int>> &grid)
		{
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
				{
					d[i][j]=INT_MAX;
					if(grid[i][j]==1)
					{
						q.push(i*n+j);
						d[i][j]=0;
					}
				}
			while(!q.empty())
			{
				int nx=q.front()/n,ny=q.front()%n;
				q.pop();
				for(int i=0;i<4;i++)
				{
					int x=nx+dx[i],y=ny+dy[i];
					if(x<0||x>=n||y<0||y>=n)
						continue;
					if(d[x][y]>d[nx][ny]+1)
					{
						d[x][y]=d[nx][ny]+1;
						q.push(x*n+y);
					}
				}
			}
		}
		bool check(int m,const vector<vector<int>> &grid)
		{
			memset(v,false,sizeof(v));
			q.push(0);
			v[0][0]=true;
			while(!q.empty())
			{
				int nx=q.front()/n,ny=q.front()%n;
				q.pop();
				for(int i=0;i<4;i++)
				{
					int x=nx+dx[i],y=ny+dy[i];
					if(x<0||x>=n||y<0||y>=n||v[x][y])
						continue;
					if(d[x][y]>=m)
					{
						v[x][y]=true;
						q.push(x*n+y);
					}
				}
			}
			return v[n-1][n-1];
		}
		int maximumSafenessFactor(vector<vector<int>>& grid) {
			n=grid.size();
			init(grid);
			int l=0,r=d[0][0];
			while(l<r)
			{
				int m=(l+r+1)>>1;
				if(check(m,grid))
					l=m+1;
				else
					r=m;
			}
			return l;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> grid = {{1,0,0},{0,0,0},{0,0,1}};
	cout<<s.maximumSafenessFactor(grid)<<endl;
	grid.clear();grid={{0,0,1},{0,0,0},{0,0,0}};
	cout<<s.maximumSafenessFactor(grid)<<endl;
	grid.clear();grid= {{0,0,0,1},{0,0,0,0},{0,0,0,0},{1,0,0,0}};
	cout<<s.maximumSafenessFactor(grid)<<endl;
	return 0;
}

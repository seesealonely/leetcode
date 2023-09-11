/*
   You are given a 0-indexed 2D integer matrix grid of size 3 * 3, representing the number of stones in each cell. The grid contains exactly 9 stones, and there can be multiple stones in a single cell.

   In one move, you can move a single stone from its current cell to any other cell if the two cells share a side.

   Return the minimum number of moves required to place one stone in each cell.



   Example 1:

Input: grid = [[1,1,0],[1,1,1],[1,2,1]]
Output: 3
Explanation: One possible sequence of moves to place one stone in each cell is: 
1- Move one stone from cell (2,1) to cell (2,2).
2- Move one stone from cell (2,2) to cell (1,2).
3- Move one stone from cell (1,2) to cell (0,2).
In total, it takes 3 moves to place one stone in each cell of the grid.
It can be shown that 3 is the minimum number of moves required to place one stone in each cell.

Example 2:

Input: grid = [[1,3,0],[1,0,0],[1,0,3]]
Output: 4
Explanation: One possible sequence of moves to place one stone in each cell is:
1- Move one stone from cell (0,1) to cell (0,2).
2- Move one stone from cell (0,1) to cell (1,1).
3- Move one stone from cell (2,2) to cell (1,2).
4- Move one stone from cell (2,2) to cell (2,1).
In total, it takes 4 moves to place one stone in each cell of the grid.
It can be shown that 4 is the minimum number of moves required to place one stone in each cell.



Constraints:

grid.length == grid[i].length == 3
0 <= grid[i][j] <= 9
Sum of grid is equal to 9.

*/


#include"head.h"
class Solution {
	public:
		typedef pair<int,int> p;
		int minimumMoves(vector<vector<int>>& grid) {
			vector<p> l,r;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
				{
					if(grid[i][j]==0)
						l.push_back({i,j});
					else 
						for(int k=1;k<grid[i][j];k++)
							r.push_back({i,j});
				}
			const int n=l.size();
			vector<int> dp(1<<n);
			for(int i=1;i<(1<<n);i++)
			{
				dp[i]=1e9;
				int cnt=0;
				for(int j=0;j<n;j++)
					cnt+=i>>j&1;
				for(int j=0;j<n;j++)
					if(i>>j&1)
						dp[i]=min(dp[i],dp[i^(1<<j)]+cost(l[cnt-1],r[j]));
			}
			return dp[(1<<n)-1];
		}
		int cost(const p &x,const p &y)
		{
			return abs(x.first-y.first)+abs(x.second-y.second);
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> grid = {{1,1,0},{1,1,1},{1,2,1}};
	cout<<s.minimumMoves(grid)<<endl;
	grid.clear();grid={{1,3,0},{1,0,0},{1,0,3}};
	cout<<s.minimumMoves(grid)<<endl;
	return 0;
}

/*
   You are given a 2D matrix grid of size m x n. In one operation, you can change the value of any cell to any non-negative number. You need to perform some operations such that each cell grid[i][j] is:

   Equal to the cell below it, i.e. grid[i][j] == grid[i + 1][j] (if it exists).
   Different from the cell to its right, i.e. grid[i][j] != grid[i][j + 1] (if it exists).

   Return the minimum number of operations needed.



   Example 1:

Input: grid = [[1,0,2],[1,0,2]]

Output: 0

Explanation:

All the cells in the matrix already satisfy the properties.

Example 2:

Input: grid = [[1,1,1],[0,0,0]]

Output: 3

Explanation:

The matrix becomes [[1,0,1],[1,0,1]] which satisfies the properties, by doing these 3 operations:

Change grid[1][0] to 1.
Change grid[0][1] to 0.
Change grid[1][2] to 1.

Example 3:

Input: grid = [[1],[2],[3]]

Output: 2

Explanation:

There is a single column. We can change the value to 1 in each cell using 2 operations.



Constraints:

1 <= n, m <= 1000
0 <= grid[i][j] <= 9

*/


#include"head.h"
class Solution {
	public:
		int minimumOperations(vector<vector<int>>& grid) {
			const int r=grid.size(),c=grid[0].size();
			vector<vector<int>> cnt(c,vector<int>(10,0));
			for(int j=0;j<c;j++)
				for(int i=0;i<r;i++)
					++cnt[j][grid[i][j]];

			vector<vector<int>> cost(c,vector<int>(11));

			for(int j=0;j<c;j++)
			{
				int tot=0;
				for(int i=0;i<10;i++)
					tot+=cnt[j][i];
				for(int i=0;i<10;i++)
					cost[j][i]=tot-cnt[j][i];
				cost[j][10]=tot;
			}

			vector<vector<int>> dp(c,vector<int>(11,INT_MAX));
			dp[0]=cost[0];
			for(int i=1;i<c;i++)
				for(int j=0;j<=10;j++)
					for(int k=0;k<=10;k++)
						if(j==10||j!=k)
							dp[i][j]=min(dp[i][j],dp[i-1][k]+cost[i][j]);
			int res=INT_MAX;
			for(int i=0;i<=10;i++)
				res=min(res,dp[c-1][i]);
			return res;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>>  grid = {{1,0,2},{1,0,2}};
	cout<<s.minimumOperations(grid)<<endl;
	grid.clear();grid={{1,1,1},{0,0,0}};
	cout<<s.minimumOperations(grid)<<endl;
	return 0;
}

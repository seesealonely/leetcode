/*
   You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

   You have two robots that can collect cherries for you:

   Robot #1 is located at the top-left corner (0, 0), and
   Robot #2 is located at the top-right corner (0, cols - 1).

   Return the maximum number of cherries collection using both robots by following the rules below:

   From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
   When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
   When both robots stay in the same cell, only one takes the cherries.
   Both robots cannot move outside of the grid at any moment.
   Both robots should reach the bottom row in grid.



   Example 1:

Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.

Example 2:

Input: grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
Output: 28
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
Total of cherries: 17 + 11 = 28.



Constraints:

rows == grid.length
cols == grid[i].length
2 <= rows, cols <= 70
0 <= grid[i][j] <= 100

*/


#include"head.h"
class Solution {
	public:
		int cherryPickup(vector<vector<int>>& grid) {
			const int r=grid.size(),c=grid[0].size();

			vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,INT_MIN)));
			dp[0][0][c-1]=grid[0][0]+grid[0][c-1];

			const vector<int> dir={-1,0,1};
			for(int i=1;i<r;i++)
				for(int j=0;j<c;j++)
					for(int d1=0;d1<dir.size();d1++)
					{
						int c1=j+dir[d1];
						if(c1<0||c1>=c) continue;

						for(int k=0;k<c;k++)
							for(int d2=0;d2<dir.size();d2++)
							{
								int c2=k+dir[d2];
								if(c2<0||c2>=c) continue;
								if(j==k) dp[i][j][k]=max(dp[i][j][k],dp[i-1][c1][c2]+grid[i][j]);
								else
								dp[i][j][k]=max(dp[i][j][k],dp[i-1][c1][c2]+grid[i][j]+grid[i][k]);
							}
					}
			int res=0;
			for(int i=0;i<c;i++)
				for(int j=0;j<c;j++)
					res=max(res,dp[r-1][i][j]);

			return res;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> g={{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
	cout<<s.cherryPickup(g)<<endl;
	g.clear();g={{1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}};
	cout<<s.cherryPickup(g)<<endl;
	return 0;
}

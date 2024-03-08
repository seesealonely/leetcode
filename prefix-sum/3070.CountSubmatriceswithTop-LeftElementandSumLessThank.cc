/*
   You are given a 0-indexed integer matrix grid and an integer k.

   Return the number of
   submatrices
   that contain the top-left element of the grid, and have a sum less than or equal to k.



   Example 1:

Input: grid = [[7,6,3],[6,6,1]], k = 18
Output: 4
Explanation: There are only 4 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 18.

Example 2:

Input: grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
Output: 6
Explanation: There are only 6 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 20.



Constraints:

m == grid.length
n == grid[i].length
1 <= n, m <= 1000
0 <= grid[i][j] <= 1000
1 <= k <= 109

*/


#include"head.h"
class Solution {
	public:
		int countSubmatrices(vector<vector<int>>& grid, int k) {
		const int r=grid.size(),c=grid[0].size();
		vector<vector<int>> presum(r+1,vector<int>(c+1,0));

		int res=0;
		for(int i=1;i<r+1;i++)
			for(int j=1;j<c+1;j++)
			{
				presum[i][j]=presum[i][j-1]+presum[i-1][j]-presum[i-1][j-1]+grid[i-1][j-1];
				res+=presum[i][j]<=k;
			}
		return res;
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> grid = {{7,6,3},{6,6,1}};
	cout<<s.countSubmatrices(grid,18)<<endl;
	grid.clear();grid={{7,2,9},{1,5,0},{2,6,6}};
	cout<<s.countSubmatrices(grid,20)<<endl;
	return 0;
}

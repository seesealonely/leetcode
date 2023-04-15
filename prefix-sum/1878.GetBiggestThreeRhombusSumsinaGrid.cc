/*
   You are given an m x n integer matrix grid​​​.

   A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid​​​. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:

   Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.

   Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.



   Example 1:

Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
Output: [228,216,211]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 20 + 3 + 200 + 5 = 228
- Red: 200 + 2 + 10 + 4 = 216
- Green: 5 + 200 + 4 + 2 = 211

Example 2:

Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: [20,9,8]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 4 + 2 + 6 + 8 = 20
- Red: 9 (area 0 rhombus in the bottom right corner)
- Green: 8 (area 0 rhombus in the bottom middle)

Example 3:

Input: grid = [[7,7,7]]
Output: [7]
Explanation: All three possible rhombus sums are the same, so return [7].



Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j] <= 105

*/


#include"head.h"
class Solution {
	public:
		vector<int> getBiggestThree(vector<vector<int>>& grid) {
		const int r=grid.size(),c=grid[0].size();
		vector<vector<int>> sum1(r+2,vector<int>(c+2,0)),sum2(r+2,vector<int>(c+2,0));

		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
			{
				sum1[i][j]=sum1[i-1][j-1]+grid[i-1][j-1];
				sum2[i][j]=sum2[i-1][j+1]+grid[i-1][j-1];
			}

		set<int> s;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
			{
				s.insert(grid[i-1][j-1]);
				for(int k=1;i+k<=r&&i-k>=1&&j+k<=c&&j-k>=1;++k)
				{
					int x=sum1[i+k][j]-sum1[i][j-k];
					int y=sum1[i][j+k]-sum1[i-k][j];
					int u=sum2[i+k][j]-sum2[i][j+k];
					int v=sum2[i][j-k]-sum2[i-k][j];
					s.insert(x+y+u+v-grid[i+k-1][j-1]+grid[i-k-1][j-1]);
				}
				while(s.size()>3) s.erase(s.begin());
			}

		return vector<int>(s.rbegin(),s.rend());
		}
};


int main() 
{
	Solution s;
	vector<vector<int>> v={{3,4,5,1,3},{3,3,4,2,3},{20,30,200,40,10},{1,5,5,4,1},{4,3,2,2,5}};
	show(s.getBiggestThree(v));
	v.clear();v={{1,2,3},{4,5,6},{7,8,9}};
	show(s.getBiggestThree(v));
	v.clear();v={{7,7,7}};
	show(s.getBiggestThree(v));
	return 0;
}

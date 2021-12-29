/*
   You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k.

   The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:

   A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:

   Return the matrix after applying k cyclic rotations to it.



   Example 1:

Input: grid = [[40,10],[30,20]], k = 1
Output: [[10,20],[40,30]]
Explanation: The figures above represent the grid at every state.

Example 2:

Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
Explanation: The figures above represent the grid at every state.



Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 50
Both m and n are even integers.
1 <= grid[i][j] <= 5000
1 <= k <= 109
*/
#include"head.h"
class Solution {
	public:
		vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
		for(int t=0,d=grid.size()-1,l=0,r=grid[0].size()-1;t<d&&l<r;t++,d--,l++,r--)
		{
			const int count=2*(d-t+1)+2*(r-l+1)-4;
			const int rotate=k%count;
			for(int ro=0;ro<rotate;ro++)
			{
				const int topleftval=grid[t][l];
				for(int i=l;i<r;i++)
					grid[t][i]=grid[t][i+1];
				for(int i=t;i<d;i++)
					grid[i][r]=grid[i+1][r];
				for(int i=r;i>l;i--)
					grid[d][i]=grid[d][i-1];
				for(int i=d;i>t;i--)
					grid[i][l]=grid[i-1][l];
				grid[t+1][l]=topleftval;
			}
		}
			return grid;
		}
};
int main() 
{
	Solution s;
	vector<vector<int> > v={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	show(s.rotateGrid(v,2));
	return 0;
}

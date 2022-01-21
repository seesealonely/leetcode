/*
   You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.

   Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.



   Example 1:

Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
Output: 4
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 4.

Example 2:

Input: matrix = [[1,0,1,0,1]]
Output: 3
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 3.

Example 3:

Input: matrix = [[1,1,0],[1,0,1]]
Output: 2
Explanation: Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.



Constraints:

m == matrix.length
n == matrix[i].length
1 <= m \ 1493.LongestSubarrayof1sAfterDeletingOneElement 1493.LongestSubarrayof1sAfterDeletingOneElement.cc 1727.LargestSubmatrixWithRearrangements.cc 1800.MaximumAscendingSubarraySum 1800.MaximumAscendingSubarraySum.cc 1800.MaximumAscendingSubarraySum.h 1991.FindtheMiddleIndexinArray 1991.FindtheMiddleIndexinArray.cc 2100.FindGoodDaystoRobtheBank 2100.FindGoodDaystoRobtheBank.cc 2100.FindGoodDaystoRobtheBank.h head.cc head.h head.o lib.a l.sh makefile n <= 105
matrix[i][j] is either 0 or 1.

*/
#include"head.h"
class Solution {
	public:
		int largestSubmatrix(vector<vector<int>>& matrix) {
		const int r=matrix.size(),c=matrix[0].size();
		for(int i=1;i<r;i++)
			for(int j=0;j<c;j++)
				if(matrix[i][j])
					matrix[i][j]+=matrix[i-1][j];

		int res=0;
		for(int i=0;i<r;i++)
		{
			sort(matrix[i].begin(),matrix[i].end());
			for(int j=0;j<c;j++)
				res=max(res,matrix[i][j]*(c-j));
		}
		return res;
		}
};
int main() 
{
	Solution s;
	vector<vector<int>> v= {{0,0,1},{1,1,1},{1,0,1}};
	cout<<s.largestSubmatrix(v)<<endl;
	v.clear();v={{1,0,1,0,1}};
	cout<<s.largestSubmatrix(v)<<endl;
	v.clear();v={{1,1,0},{1,0,1}};
	cout<<s.largestSubmatrix(v)<<endl;
	return 0;
}

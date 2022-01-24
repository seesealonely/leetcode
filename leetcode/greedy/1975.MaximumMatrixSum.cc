/*
   You are given an n x n integer matrix. You can do the following operation any number of times:

   Choose any two adjacent elements of matrix and multiply each of them by -1.

   Two elements are considered adjacent if and only if they share a border.

   Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.



   Example 1:

Input: matrix = [[1,-1],[-1,1]]
Output: 4
Explanation: We can follow the following steps to reach sum equals 4:
- Multiply the 2 elements in the first row by -1.
- Multiply the 2 elements in the first column by -1.

Example 2:

Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
Output: 16
Explanation: We can follow the following step to reach sum equals 16:
- Multiply the 2 last elements in the second row by -1.



Constraints:

n == matrix.length == matrix[i].length
2 <= n <= 250
-105 <= matrix[i][j] <= 105

*/
#include"head.h"
class Solution {
	public:
		long long maxMatrixSum(vector<vector<int>>& matrix) {
		int  neg=INT_MAX,count=0;
		long long res=0;
		for(int i=0;i<matrix.size();i++)
			for(int j=0;j<matrix[0].size();j++)
			{
				if(matrix[i][j]<0)
					count++;
				neg=min(neg,abs(matrix[i][j]));
				res+=abs(matrix[i][j]);
			}
		return count%2==0?res:res-2*neg;
		}
};
int main() 
{
	Solution s;
	vector<vector<int>> v={{1,-1},{-1,1}};
	cout<<s.maxMatrixSum(v)<<endl;
	v.clear();v={{1,2,3},{-1,-2,-3},{1,2,3}};
	cout<<s.maxMatrixSum(v)<<endl;
	return 0;
}

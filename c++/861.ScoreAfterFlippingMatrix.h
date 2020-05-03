/*
We have a two dimensional matrix A where each value is 0 or 1.

A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.

After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score.

 

Example 1:

Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation:
Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

 

Note:

    1 <= A.length <= 20
    1 <= A[0].length <= 20
    A[i][j] is 0 or 1.
*/

#include"head.h"

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
	int r=A.size(),c=A[0].size(),res=(1<<(c-1))*r;
	for(int i=1;i<c;i++)
	{
		int colSum=0;
		for(int j=0;j<r;j++)
			colSum+=A[j][i]==A[j][0];	
		res+=max(colSum,r-colSum)*(1<<(c-1-i));
	}
	return res;
    }
};

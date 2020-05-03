/*
 Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

Example 1:
Input:

0 0 0
0 1 0
0 0 0

Output:

0 0 0
0 1 0
0 0 0

Example 2:
Input:

0 0 0
0 1 0
1 1 1

Output:

0 0 0
0 1 0
1 2 1

Note:

    The number of elements of the given matrix will not exceed 10,000.
    There are at least one 0 in the given matrix.
    The cells are adjacent in only four directions: up, down, left and right.

*/

#include"head.h"

class Solution {
public:
    vector<vector<int> > updateMatrix(vector<vector<int> >& matrix) {
       int row=matrix.size(),col=matrix[0].size();
	vector<vector<int> > dp(row,vector<int>(col,INT_MAX));
	for(int k=0;k<2;++k)
		for(int i=k?row-1:0;k?i>=0:i<row;k?--i:++i)
			for(int j=k?col-1:0;k?j>=0:j<col;k?--j:++j)
				if(matrix[i][j]==0)
					dp[i][j]=0;
				else
				{
					if(i&&dp[i-1][j]!=INT_MAX&&dp[i][j]>dp[i-1][j]+1)
			dp[i][j]=dp[i-1][j]+1;
if(j&&dp[i][j-1]!=INT_MAX&&dp[i][j]>dp[i][j-1]+1)
			dp[i][j]=dp[i][j-1]+1;
	if(i<row-1&&dp[i+1][j]!=INT_MAX&&dp[i][j]>dp[i+1][j]+1)
			dp[i][j]=dp[i+1][j]+1;
if(j<col-1&&dp[i][j+1]!=INT_MAX&&dp[i][j]>dp[i][j+1]+1)
	dp[i][j]=dp[i][j+1]+1;
				} 
	return dp;
    }
};

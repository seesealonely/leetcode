/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:

Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12

Note:

    You may assume that the matrix does not change.
    There are many calls to sumRegion function.
    You may assume that row1 ≤ row2 and col1 ≤ col2.

*/

#include"head.h"

class NumMatrix {
public:
    NumMatrix(vector<vector<int> > matrix) {
   if(matrix.empty()||!matrix.size()||!matrix[0].size())
	return ;
	int row=matrix.size(),col=matrix[0].size();
//	dp=new int[row+1][col+1];
	for(int i=1;i<row+1;++i)
		for(int j=1;j<col+1;++j)
		dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i-1][j-1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int iMin=min(row1,row2);
	int iMax=max(row1,row2);
	int jMin=min(col1,col2);
	int jMax=max(col1,col2);
       	return (int)(dp[iMax+1][jMax+1]-dp[iMax+1][jMin]-dp[iMin][jMax+1]+dp[iMin][jMin]); 
    }
    private:
 vector<vector<int> > dp;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

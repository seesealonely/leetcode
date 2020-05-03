/*
Given a m * n matrix mat and an integer K, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for i - K <= r <= i + K, j - K <= c <= j + K, and (r, c) is a valid position in the matrix.

 

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]

Example 2:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]

 

Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n, K <= 100
    1 <= mat[i][j] <= 100

*/

#define c11
#include"head.h"

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
	vector<vector<int> > sum(mat.size()+1,vector<int>(mat[0].size()+1,0));
	vector<vector<int> > res(mat.size(),vector<int>(mat[0].size(),0));
	int maxr=mat.size(),maxc=mat[0].size();
	for(int i=0;i<maxr;i++)
	for(int j=0;j<maxc;j++)
	sum[i+1][j+1]=sum[i+1][j]+sum[i][j+1]+mat[i][j]-sum[i][j];
	for(int i=0;i<maxr;i++)
	for(int j=0;j<maxc;j++)
	{
		int r1=max(0,i-K);int c1=max(0,j-K);int r2=min(maxr,i+K+1);int c2=min(maxc,j+K+1);
	res[i][j]=sum[r2][c2]-sum[r2][c1]-sum[r1][c2]+sum[r1][c1];	
	}
	return res;
    }
};

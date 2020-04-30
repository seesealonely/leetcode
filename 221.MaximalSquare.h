/*
 Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4. 
*/
#include"head.h"

int  firstWay(vector<vector<char> >& matrix) {
int  row=matrix.size(),col=row>0?matrix[0].size():0,maxl=0;
	vector<vector<int> > dp(row+1,vector<int> (col+1,0));
	for(int i=1;i<row+1;i++)
		for(int j=1;j<col+1;j++)
		if(matrix[i-1][j-1]=='1')
		{
			dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
		maxl=max(dp[i][j],maxl);
		}
		return maxl*maxl;
}
class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
	return firstWay(matrix);        
    }
};

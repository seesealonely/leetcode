/*
 Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4. 
*/
#include"221.MaximalSquare.h"
int main()
{
	vector<vector<char> > v(5,vector<char>(5,'0'));
	v[0][0]=v[0][2]='1';
	v[1][0]=v[1][2]=v[1][3]=v[1][4]='1';
	v[2][0]=v[2][1]=v[2][2]=v[2][3]=v[2][4]='1';
	v[4][0]=v[0][3]='1';
	Solution s;
	cout<<s.maximalSquare(v)<<endl;
		return 0;
}


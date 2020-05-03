/*
   Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

#include"64.MinimumPathSum.h"

int main()
{
	vector<vector<int> > v;
	for(int i=0;i<3;++i)
	{
		v.push_back({});
		for(int j=0;j<3;++j)
			v[i].push_back(i*3+j+1);
	}
	Solution s;
	cout<<s.minPathSum(v)<<endl;
	return 0;
}

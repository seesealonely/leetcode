#include"63.h"
int main()
{
	vector<vector<int > > v(3,vector<int>(3,0));
	v[1][1]=1;
	Solution s;
	cout<<s.uniquePathsWithObstacles(v)<<endl;
	return 0;
}

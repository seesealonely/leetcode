/*
*/

#include"867.h"

int main()
{
	vector<vector<int> > v(3,vector<int>(3,0));
	int plus=1;
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
		v[i][j]=plus++;
	Solution s;
	show(s.transpose(v));
	v.resize(2);
	show(s.transpose(v));
	return 0;
}

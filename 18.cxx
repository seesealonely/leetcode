#include"18.h"
int main(void)
{
	int vv[6]={1,0,-1,0,-2,2};
	vector<int> v(vv,vv+6);
	int t=0;
	Solution s;
	vector<vector<int> >p=s.fourSum(v,t);
	show(p);
	return 0;	
}

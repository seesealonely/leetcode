#include"16.3SumClosest.h"
int main()
{
	int  vv[]={-1,2,1,-4};
	vector<int> v(vv,vv+4);
	Solution s;
	cout<<s.threeSumClosest(v,1)<<endl;
}

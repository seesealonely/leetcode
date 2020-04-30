#include"88.h"
int main()
{
	int v1[]={1,2,3,4};
	int v2[]={5};
	vector<int> vv1(v1,v1+4),vv2(v2,v2+1);
	Solution s;
s.merge(vv1,vv1.size(),vv2,vv2.size());
}

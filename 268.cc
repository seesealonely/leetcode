#include"268.h"
int main()
{
	int v1[]={1,2,3,4,5};
	vector<int> vv1(v1,v1+5);
	int v2[]={0,1,2,3,5};
	vector<int> vv2(v2,v2+5);
	Solution s;
	cout<<s.missingNumber(vv1)<<endl;
	cout<<s.missingNumber(vv2)<<endl;
	return 0;
}

#include"152.h"
int main()
{
	int vv[]={2,3,-2,4};
	vector<int> v(vv,vv+4);
	int v1[]={-3,-4};
	vector<int> v2(v1,v1+2);
	int v3[]={-4,-3,-2};
	vector<int> v33(v3,v3+3);
	Solution s;
	cout<<s.maxProduct(v)<<endl;
	cout<<s.maxProduct(v2)<<endl;
	cout<<s.maxProduct(v33)<<endl;
	return 0;
}

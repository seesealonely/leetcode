#include"217.h"
int main()
{
	int vv1[]={1,2,3,4};
	int vv2[]={1,2,3,4,1};
	int vv3[]={0};
	vector<int> v1(vv1,vv1+4);
	vector<int> v2(vv2,vv2+5);
	vector<int> v3(vv3,vv3+1);
	Solution s;
	cout<<s.containsDuplicate(v1)<<endl;
	cout<<s.containsDuplicate(v2)<<endl;
	cout<<s.containsDuplicate(v3)<<endl;
	return 0;
}

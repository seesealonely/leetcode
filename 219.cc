#include"219.h"
int main()
{
	int vv[]={1,2,3,4,5,1};
	int vv1[]={1};
	vector<int> v(vv,vv+6);
	vector<int> v1(vv1,vv1+1);
	Solution s;
	cout<<s.containsNearbyDuplicate(v,8)<<endl;
	cout<<s.containsNearbyDuplicate(v1,1)<<endl;
	return 0;
}

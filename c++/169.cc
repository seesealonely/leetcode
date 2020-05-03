#include"169.h"
int main()
{
	int vv[]={1,2,3,4,5,6,7,7,7,7,7,7,7,7,8,9,10,7,7,7,7,7,7};
	vector<int> v(vv,vv+18);
	Solution s;
	int res=s.majorityElement(v);
	cout<<res<<endl;
	return 0;
}

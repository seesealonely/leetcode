#include"198.h"
int main()
{
	int vv[]={2,1,1,2};
	vector<int> v(vv,vv+4);
	Solution s;
	cout<<s.rob(v)<<endl;
	return 0;
}

#include"80.h"
int main()
{
	int vv[]={1,1,1,2,2,3};
	vector<int> v(vv,vv+6);
	Solution s;
	cout<<s.removeDuplicates(v)<<endl;
	return 0;
}

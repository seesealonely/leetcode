#include"485.h"
int main()
{
	int vv[]={1,1,0,1,1,1};
	vector<int> v(vv,vv+6);
	Solution s;
	cout<<s.findMaxConsecutiveOnes(v)<<endl;
	return 0;
}

#include"53.h"
int main()
{
	int vv[]={-2,1,-3,4,-1,2,1,-5,4};//{-2,1,-3,4,-1,2,1,-5,4};
	vector<int> v(vv,vv+9);
	Solution s;
	cout<<s.maxSubArray(v)<<endl;
	return 0;
}

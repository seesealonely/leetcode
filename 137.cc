#include"137.h"
int main()
{
	int v[]={1,1,1,2,2,2,4};
	vector<int > vv(v,v+7);
	Solution s;
	cout<<s.singleNumber(vv)<<endl;
	return 0;
}

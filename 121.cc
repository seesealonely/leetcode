#include"121.h"
int main()
{
	int vv[]={7,1,5,3,6,4};
	vector<int> v(vv,vv+6);
	Solution s;
	cout<<s.maxProfit(v)<<endl;
	return 0;
}

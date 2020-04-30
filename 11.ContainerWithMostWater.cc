#include"11.ContainerWithMostWater.h"
int main()
{
	int vv[]={1,2,3,4,5,6};
	vector<int> v(vv,vv+6);
	Solution s;
	cout<<s.maxArea(v)<<endl;
}

#include"215.h"
int main()
{
int v1[]={3,2,1,5,6,4};	
vector<int> v(v1,v1+7);
	Solution s;
	cout<<s.findKthLargest(v,2)<<endl;
	return 0;
}

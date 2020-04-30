/*
 Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space. 
*/
#include"41.FirstMissingPositive.h"
int main()
{
	int vv[]={5,4,3,2};
	vector<int> v(vv,vv+4);
	Solution s;
	int res=s.firstMissingPositive(v);
	cout<<res<<endl;
	int vv1[]={-1,4,2,1,9,10};
	vector<int> v1(vv1,vv1+6);
	res=s.firstMissingPositive(v1);
	cout<<res<<endl;
	return 0;
}


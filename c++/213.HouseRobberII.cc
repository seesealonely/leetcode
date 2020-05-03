/*
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

#include"213.HouseRobberII.h"

int main()
{
	int vv[]={2,1,1,2,3,4,1,2,3};
	vector<int> v(vv,vv+9);
	Solution s;
	cout<<s.rob(v)<<endl;
	return 0;
}

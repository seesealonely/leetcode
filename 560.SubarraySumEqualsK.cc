/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2

Note:

    The length of the array is in range [1, 20,000].
    The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

*/

#include"560.SubarraySumEqualsK.h"

int main()
{
	vector<int> v;
	v.push_back(1);v.push_back(1);v.push_back(1);
	Solution s;
	cout<<s.subarraySum(v,2)<<endl;
	v.clear();
	for(int i=0;i<10;i++) v.push_back(0);
	cout<<s.subarraySum(v,0)<<endl;
	return 0;
}

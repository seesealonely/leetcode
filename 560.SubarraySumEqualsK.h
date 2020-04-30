/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2

Note:

    The length of the array is in range [1, 20,000].
    The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

*/

#include"head.h"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
 	map<int,int> m;
	m[0]=1;       
	int res=0,sum=0;
	for(int i=0;i<nums.size();i++)
	{
		sum+=nums[i];
		if(m[sum-k])
			res+=m[sum-k];
		m[sum]++;
	}
	return res;
    }
};

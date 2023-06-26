/*
   You are given a binary array nums.

   A subarray of an array is good if it contains exactly one element with the value 1.

   Return an integer denoting the number of ways to split the array nums into good subarrays. As the number may be too large, return it modulo 109 + 7.

   A subarray is a contiguous non-empty sequence of elements within an array.



   Example 1:

Input: nums = [0,1,0,0,1]
Output: 3
Explanation: There are 3 ways to split nums into good subarrays:
- [0,1] [0,0,1]
- [0,1,0] [0,1]
- [0,1,0,0] [1]

Example 2:

Input: nums = [0,1,0]
Output: 1
Explanation: There is 1 way to split nums into good subarrays:
- [0,1,0]



Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 1

*/


#include"head.h"
class Solution {
	public:
		int numberOfGoodSubarraySplits(vector<int>& nums) {
		const int n=nums.size(),mod=1e9+7;

		int res=1,pre=-1;
		for(int i=0;i<n;i++)
		{
			if(nums[i]!=1)
				continue;

			if(pre!=-1)
				res=(long long)res*(i-pre)%mod;

			pre=i;

		}

		return pre==-1?0:res;
		}
};


int main() 
{
	Solution s;
	vector<int> nums={0,1,0,0,1};
	cout<<s.numberOfGoodSubarraySplits(nums)<<endl;
	nums.clear();nums={0,1,0};
	cout<<s.numberOfGoodSubarraySplits(nums)<<endl;
	return 0;
}

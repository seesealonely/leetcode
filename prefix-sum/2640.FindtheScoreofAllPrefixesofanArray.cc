/*
   We define the conversion array conver of an array arr as follows:

   conver[i] = arr[i] + max(arr[0..i]) where max(arr[0..i]) is the maximum value of arr[j] over 0 <= j <= i.

   We also define the score of an array arr as the sum of the values of the conversion array of arr.

   Given a 0-indexed integer array nums of length n, return an array ans of length n where ans[i] is the score of the prefix nums[0..i].



   Example 1:

Input: nums = [2,3,7,5,10]
Output: [4,10,24,36,56]
Explanation:
For the prefix [2], the conversion array is [4] hence the score is 4
For the prefix [2, 3], the conversion array is [4, 6] hence the score is 10
For the prefix [2, 3, 7], the conversion array is [4, 6, 14] hence the score is 24
For the prefix [2, 3, 7, 5], the conversion array is [4, 6, 14, 12] hence the score is 36
For the prefix [2, 3, 7, 5, 10], the conversion array is [4, 6, 14, 12, 20] hence the score is 56

Example 2:

Input: nums = [1,1,2,4,8,16]
Output: [2,4,8,16,32,64]
Explanation:
For the prefix [1], the conversion array is [2] hence the score is 2
For the prefix [1, 1], the conversion array is [2, 2] hence the score is 4
For the prefix [1, 1, 2], the conversion array is [2, 2, 4] hence the score is 8
For the prefix [1, 1, 2, 4], the conversion array is [2, 2, 4, 8] hence the score is 16
For the prefix [1, 1, 2, 4, 8], the conversion array is [2, 2, 4, 8, 16] hence the score is 32
For the prefix [1, 1, 2, 4, 8, 16], the conversion array is [2, 2, 4, 8, 16, 32] hence the score is 64



Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109

*/


#include"head.h"
class Solution {
	public:
		vector<long long> findPrefixScore(vector<int>& nums) {
		int n=nums.size(),mx=nums[0];
		for(int i=0;i<nums.size();i++)
		{
			mx=max(nums[i],mx);
			nums[i]+=mx;
		}

		vector<long long >presum(n,0);
		presum[0]=nums[0];
		for(int i=1;i<n;i++)
		presum[i]=presum[i-1]+nums[i];
		return presum;
		}
};


int main() 
{
	Solution s;
	vector<int> v={2,3,7,5,10};
	show(s.findPrefixScore(v));
	v.clear();v={1,1,2,4,8,16};
	show(s.findPrefixScore(v));
	return 0;
}

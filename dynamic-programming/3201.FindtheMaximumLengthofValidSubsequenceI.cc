/*
   You are given an integer array nums.

   A
   subsequence
   sub of nums with length x is called valid if it satisfies:

   (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.

   Return the length of the longest valid subsequence of nums.

   A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.



   Example 1:

Input: nums = [1,2,3,4]

Output: 4

Explanation:

The longest valid subsequence is [1, 2, 3, 4].

Example 2:

Input: nums = [1,2,1,1,2,1,2]

Output: 6

Explanation:

The longest valid subsequence is [1, 2, 1, 2, 1, 2].

Example 3:

Input: nums = [1,3]

Output: 2

Explanation:

The longest valid subsequence is [1, 3].



Constraints:

2 <= nums.length <= 2 * 105
1 <= nums[i] <= 107

*/


#include"head.h"
class Solution {
	public:
		int maximumLength(vector<int>& nums) {
		int res=0,n=nums.size();
		for(int i=0;i<2;i++)
		{
			vector<int> dp(2);
			for(int j=0;j<n;j++)
			{
				int x=nums[j]%2;
				dp[x]=dp[(i-x+2)%2]+1;
				res=max(res,dp[x]);
			}
		}
		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> nums={1,2,3,4};
	cout<<s.maximumLength(nums)<<endl;
	nums.clear();nums={1,2,1,1,2,1,2};
	cout<<s.maximumLength(nums)<<endl;
	return 0;
}

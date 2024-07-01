/*
   You are given an integer array nums and a positive integer k.

   A
   subsequence
   sub of nums with length x is called valid if it satisfies:

   (sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.

   Return the length of the longest valid subsequence of nums.



   Example 1:

Input: nums = [1,2,3,4,5], k = 2

Output: 5

Explanation:

The longest valid subsequence is [1, 2, 3, 4, 5].

Example 2:

Input: nums = [1,4,2,3,1,4], k = 3

Output: 4

Explanation:

The longest valid subsequence is [1, 4, 1, 4].



Constraints:

2 <= nums.length <= 103
1 <= nums[i] <= 107
1 <= k <= 103

*/


#include"head.h"
class Solution {
	public:
		int maximumLength(vector<int>& nums, int k) {
			int res=0,n=nums.size();
			for(int i=0;i<k;i++)
			{
				vector<int> dp(k);
				for(int j=0;j<n;j++)
				{
					int x=nums[j]%k;
					dp[x]=dp[(i-x+k)%k]+1;
					res=max(res,dp[x]);
				}
			}
			return res;
		}
};


int main() 
{
	Solution s;
	vector<int> nums={1,2,3,4,5};
	cout<<s.maximumLength(nums,2)<<endl;
	nums.clear();nums={1,4,2,3,1,4};
	cout<<s.maximumLength(nums,3)<<endl;
	return 0;
}

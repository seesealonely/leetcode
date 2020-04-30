/*
   Given an unsorted array of integers, find the number of longest increasing subsequence.

   Example 1:

Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:

Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.

Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int. 
*/

#include"head.h"
using namespace std;
int dp(vector<int> nums)
{
	vector<pair<int,int> > dp(nums.size(),{1,1});
	int submax=0,res=0;
	if(nums.empty()) return 0;
	for(int i=0;i<nums.size();i++)
	{
		for(int j=0;i>j;j++)
		{
			if(nums[j]<nums[i])
			{
				if(dp[i].first==dp[j].first+1)
					dp[i].second+=dp[j].second;
				if(dp[j].first+1>dp[i].first)
					dp[i]={dp[j].first+1,dp[j].second};
			}	
		}
			if(dp[i].first==submax) res+=dp[i].second;
			if(dp[i].first>submax)
			{
				submax=dp[i].first;
				res=dp[i].second;
			}
	}
	return res;
}
class Solution {
	public:
		int findNumberOfLIS(vector<int>& nums) {
			return dp(nums);
		}
};

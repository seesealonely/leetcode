/*
   Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

   Si % Sj = 0 or Sj % Si = 0.

   If there are multiple solutions, return any subset is fine.

   Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)

Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]

*/

#include"head.h"

class Solution {
	public:
		vector<int> largestDivisibleSubset(vector<int>& nums) {
			return dp(nums);
		}
		vector<int> dp(vector<int>& nums) {
			vector<int> dp(nums.size(),0),index,res;
			int posi=-1;
			for(int i=1;i<nums.size();i++)
			{
				posi=-1;
				for(int j=i-1;j>=0;j--)
					if(nums[i]%nums[j]==0||nums[j]%nums[i]==0)
					{
						if(dp[i]<=dp[j])
						{
							dp[i]=dp[j]+1;	
							if(posi<j) posi=j;
						}
					}
				index.push_back(posi);		
			}
			for(vector<int>::iterator it=nums.begin();it!=nums.end();it++)
				res.push_back(nums[*it]);
			return res;
		}
};

#include<iostream>
#include<vector>
using namespace std;
//dp
/*
class Solution
{
	public:
		int maxSubArray(vector<int>& nums)
		{
			int dp[nums.size()];
			dp[0]=nums[0];
			int res=0;
			for(int i=1;i<=nums.size();i++)
			{
			dp[i]=nums[i]+(dp[i-1]>0?dp[i-1]:0);
			res=max(res,dp[i]);	
			}        
		return res;
		}
};
*/
class Solution
{
	public:
		int maxSubArray(vector<int>& nums)
		{
			int dp;
			dp=nums[0];
			int res=nums[0];
			for(int i=1;i<nums.size();i++)
			{
			dp=nums[i]+(dp>0?dp:0);
			res=max(res,dp);	
			}        
		return res;
		}
};

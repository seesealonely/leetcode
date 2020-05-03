/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

    You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
    0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

*/

#include"head.h"

class Solution {
public:
    int maxCoins(vector<int>& nums) {
	return help(nums);
    }
    int help(vector<int>& nums) {
	int n=nums.size();
	nums.insert(nums.begin(),1);
	nums.insert(nums.end(),1);
	vector<vector<int> > dp(n+2,vector<int>(n+2,0));
	for(int  len=2;len<n+2;len++)
	{
		for(int left=0;left<n+2-len;left++)
		{
			int right=left+len;
			for(int k=left+1;k<right;k++)
			dp[left][right]=max(dp[left][right],dp[left][k]+nums[left]*nums[k]*nums[right]+dp[k][right]);
		}
	}
	return dp[0][n+1];
	}
};

/*
Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:

Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

Note:
1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.

*/

#include"head.h"

int dp(vector<int> &nums,int k)
{
	
}
bool dfs(vector<int> &nums,int k,int target,int begin,int add,vector<bool> visit)
{
	if(k==1) return true;
	if(target==add) 
		dfs(nums,k-1,target,0,0,visit);	
	for(int i=begin;i<nums.size();i++)
	{
		visit[i]=true;
		if(dfs(nums,k-1,target,i+1,add+nums[i],visit))
		return true;	
		visit[i]=false;
	}
	return false;
}
bool dfsmain(vector<int> &nums,int k)
{
	int sum=0;
	for(int i=0;i<nums.size();i++)
	sum+=nums[i];
	if(nums.size()<k||sum%k)
		return false;
	vector<bool> visit(nums.size(),false);	
	return	dfs(nums,k,sum/k,0,0,visit);	
}
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
	return dfsmain(nums,k);        
    }
};

/*
 You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:

Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.

Note:

    The length of the given array is positive and will not exceed 20.
    The sum of elements in the given array will not exceed 1000.
    Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

#include"head.h"

using namespace std;

int dp(vector<int> &nums,int s)
{
	int sum=0;
	for(int i=0;i<nums.size();i++)
		sum+=nums[i];
	if((sum+s)%2) return 0;
	int subsum=(sum+s)/2;
	vector<vector<int> > dp(nums.size()+1,vector<int>(subsum+1,INT_MIN));

	for(int i=0;i<nums.size();i++)
	dp[i][0]=1;
	for(int i=1;i<nums.size()+1;i++)
		for(int j=0;j<subsum+1;j++)
			if(j>=nums[i-1])
			dp[i][j]+=dp[i-1][j-nums[i-1]]+nums[i-1];	
			else 
			dp[i][j]=dp[i-1][j];
 	return dp[nums.size()][subsum];
}
int optimizitiondp(vector<int> &nums,int s)
{
	int sum=0;
	for(int i=0;i<nums.size();i++)
		sum+=nums[i];
	if((sum+s)%2) return 0;
	int subsum=(sum+s)/2;
	vector<int>  dp(subsum+1,0);
	dp[0]=1;
	for(int i=1;i<nums.size()+1;i++)
		for(int j=0;j<subsum+1;j++)
			if(j>=nums[i-1])
			dp[j]+=dp[j-nums[i-1]]+nums[i-1];	
			else 
			dp[j]=dp[j-1];
 	return dp[subsum];
}
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
	return optimizitiondp(nums,S);        
    }
};

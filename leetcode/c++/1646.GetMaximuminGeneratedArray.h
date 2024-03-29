/*
   You are given an integer n. An array nums of length n + 1 is generated in the following way:

   nums[0] = 0
   nums[1] = 1
   nums[2 
   nums[2

   Return the maximum integer in the array nums​​​.



   Example 1:

Input: n = 7
Output: 3
Explanation: According to the given rules:
nums[0] = 0
nums[1] = 1
nums[(1 
nums[(1
nums[(2
nums[(2
nums[(3
nums[(3
Hence, nums = [0,1,1,2,1,3,2,3], and the maximum is 3.

Example 2:

Input: n = 2
Output: 1
Explanation: According to the given rules, the maximum between nums[0], nums[1], and nums[2] is 1.

Example 3:

Input: n = 3
Output: 2
Explanation: According to the given rules, the maximum between nums[0], nums[1], nums[2], and nums[3] is 2.



Constraints:

0 <= n <= 100

*/
#include"head.h"
class Solution {
	public:
		int getMaximumGenerated(int n) {
		if(n<=1)
			return n;
		int res=0;
		vector<int> dp(n+1);
		dp[0]=0;dp[1]=1;
		for(int i=2;i<=n;i++)
		{
			dp[i]=i%2==0?dp[i>>1]:dp[i>>1]+dp[(i>>1)+1];
			res=max(res,dp[i]);
		}
		return res;
		}
		int dfs(int n) {
		if(!n) return 0;
		if(n==1) return 1;
		if(n%2==1)
		return dfs(n/2)+dfs(n/2+1);
		else
			return dfs(n/2);
		}
};

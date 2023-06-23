/*
   You are given a 0-indexed integer array nums containing n distinct positive integers. A permutation of nums is called special if:

   For all indexes 0 <= i < n - 1, either nums[i] % nums[i+1] == 0 or nums[i+1] % nums[i] == 0.

   Return the total number of special permutations. As the answer could be large, return it modulo 109 + 7.



   Example 1:

Input: nums = [2,3,6]
Output: 2
Explanation: [3,6,2] and [2,6,3] are the two special permutations of nums.

Example 2:

Input: nums = [1,4,3]
Output: 2
Explanation: [3,1,4] and [4,1,3] are the two special permutations of nums.



Constraints:

2 <= nums.length <= 14
1 <= nums[i] <= 109

*/


#include"head.h"
const int N=14,mod=1e9+7;
class Solution {
	public:
		int dp[1<<N][N];
		int specialPerm(vector<int>& nums) {
			const int n=nums.size();
			int res=0;
			memset(dp,-1,sizeof(dp));
			int mask=(1<<n)-1;
			for(int i=0;i<n;i++)
			res=(res+dfs(mask^(1<<i),nums,i))%mod;;
			return res;
		}
		int  dfs(int mask ,vector<int> &nums,int start)
		{
			if(mask==0) return 1;
			if(dp[1<<start][start]!=-1) return dp[1<<start][start];
			int res=0;
			for(int i=0;i<nums.size();i++)
			{
				if(check(nums,i,start)&&((mask>>i)&1)==1)
					res=(res+dfs(mask^(1<<i),nums,i))%mod;
			}
			return dp[mask][start]=res;
		}
		bool check(vector<int> &nums,int i,int j)
		{
			return nums[i]%nums[j]==0||nums[j]%nums[i]==0;
		}
};


int main() 
{
	Solution s;
	vector<int> nums={2,3,6};
	cout<<s.specialPerm(nums)<<endl;
	nums.clear();nums={1,4,3};
	cout<<s.specialPerm(nums)<<endl;
	return 0;
}

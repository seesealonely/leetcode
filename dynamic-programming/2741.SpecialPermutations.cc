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

const int N=16,mod=1e9+7;
*/


#include"head.h"
const int N=16,mod=1e9+7;
class Solution {
	public:
		int dp[1<<N][N];
		int specialPerm(vector<int>& nums) {
			const int n=nums.size();
			int res=0;
			memset(dp,-1,sizeof(dp));
			for(int i=0;i<n;i++)
				dp[1<<i][i]=1;
			for(int i=1;i<1<<n;i++)
				for(int j=0;j<n;j++)
				{
					if(dp[i][j]!=-1||dp[i][j]==0) continue;
					dp[i][j]=0;
					if(i>>j&1)
					{
						for(int k=0;k<n;k++)
						{
							if(k==j) continue;
							if((i>>k&1)&&check(nums,j,k))
								dp[i][j]=(dp[i][j]+dp[i-(1<<j)][k])%mod;
						}
					}
				}
			for(int i=0;i<n;i++)
				res=(res+dp[(1<<n)-1][i])%mod;
			return res;
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

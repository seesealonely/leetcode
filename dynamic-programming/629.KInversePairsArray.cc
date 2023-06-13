/*
   For an integer array nums, an inverse pair is a pair of integers [i, j] where 0 <= i < j < nums.length and nums[i] > nums[j].

   Given two integers n and k, return the number of different arrays consist of numbers from 1 to n such that there are exactly k inverse pairs. Since the answer can be huge, return it modulo 109 + 7.



   Example 1:

Input: n = 3, k = 0
Output: 1
Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.

Example 2:

Input: n = 3, k = 1
Output: 2
Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.



Constraints:

1 <= n <= 1000
0 <= k <= 1000

*/


#include"head.h"
class Solution {
	public:
		int kInversePairs(int n, int k) {
		const int mod=1e9+7;
		vector<vector<int>> dp(n+1,vector<int>(k+1)),sum(n+1,vector<int>(k+1));

		for(int i=0;i<=k;i++)
			sum[1][i]=1;

		dp[1][0]=1;
		for(int i=2;i<=n;i++)
			for(int j=0;j<=k;j++)
			{
				if(j<i)
					dp[i][j]=sum[i-1][j];
				else
					dp[i][j]=(sum[i-1][j]-sum[i-1][j-i]+mod)%mod;

				if(j==0)
					sum[i][j]=dp[i][j];
				else
					sum[i][j]=(sum[i][j-1]+dp[i][j])%mod;
			}

		return dp[n][k];

		}
};


int main() 
{
	Solution s;
	cout<<s.kInversePairs(3,0)<<endl;
	cout<<s.kInversePairs(3,1)<<endl;
	return 0;
}

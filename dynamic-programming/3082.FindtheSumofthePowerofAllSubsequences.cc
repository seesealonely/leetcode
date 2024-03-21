/*
   You are given an integer array nums of length n and a positive integer k.

   The power of an array of integers is defined as the number of
   subsequences
   with their sum equal to k.

   Return the sum of power of all subsequences of nums.

   Since the answer may be very large, return it modulo 109 + 7.



   Example 1:

Input: nums = [1,2,3], k = 3

Output: 6

Explanation:

There are 5 subsequences of nums with non-zero power:

The subsequence [1,2,3] has 2 subsequences with sum == 3: [1,2,3] and [1,2,3].
The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].
The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].
The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].
The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].

Hence the answer is 2 + 1 + 1 + 1 + 1 = 6.

Example 2:

Input: nums = [2,3,3], k = 5

Output: 4

Explanation:

There are 3 subsequences of nums with non-zero power:

The subsequence [2,3,3] has 2 subsequences with sum == 5: [2,3,3] and [2,3,3].
The subsequence [2,3,3] has 1 subsequence with sum == 5: [2,3,3].
The subsequence [2,3,3] has 1 subsequence with sum == 5: [2,3,3].

Hence the answer is 2 + 1 + 1 = 4.

Example 3:

Input: nums = [1,2,3], k = 7

Output: 0

Explanation: There exists no subsequence with sum 7. Hence all subsequences of nums have power = 0.



Constraints:

1 <= n <= 100
1 <= nums[i] <= 104
1 <= k <= 100

*/


#include"head.h"
class Solution {
	public:
		typedef long long ll;
		static const int N=105;
		int dp[N][N],p[N];
		int sumOfPower(vector<int>& nums, int k) {
		const int n=nums.size(),mod=1e9+7;

		p[0]=1;
		for(int i=1;i<n;i++)
			p[i]=p[i-1]*2%mod;

		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		int res=0;
		for(int i=1;i<=n;i++)
			for(int j=i;j>=1;j--)
			{
				int x=nums[i-1];
				for(int s=k;s>=x;s--)
					dp[j][s]=(dp[j][s]+dp[j-1][s-x])%mod;
			}

		for(int i=1;i<=n;i++)
			res=(res+(ll)(dp[i][k])*p[n-i])%mod;
		return res;
		}
};


int main() 
{
	Solution s;
	vector<int> nums={1,2,3};
	cout<<s.sumOfPower(nums,3)<<endl;
	nums.clear();nums={2,3,3};
	cout<<s.sumOfPower(nums,5)<<endl;
	nums.clear();nums={1,2,3};
	cout<<s.sumOfPower(nums,7)<<endl;
	return 0;
}

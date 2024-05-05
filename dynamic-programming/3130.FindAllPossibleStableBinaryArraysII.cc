/*
   You are given 3 positive integers zero, one, and limit.

   A
   binary array
   arr is called stable if:

   The number of occurrences of 0 in arr is exactly zero.
   The number of occurrences of 1 in arr is exactly one.
   Each
   subarray
   of arr with a size greater than limit must contain both 0 and 1.

   Return the total number of stable binary arrays.

   Since the answer may be very large, return it modulo 109 + 7.



   Example 1:

Input: zero = 1, one = 1, limit = 2

Output: 2

Explanation:

The two possible stable binary arrays are [1,0] and [0,1].

Example 2:

Input: zero = 1, one = 2, limit = 1

Output: 1

Explanation:

The only possible stable binary array is [1,0,1].

Example 3:

Input: zero = 3, one = 3, limit = 2

Output: 14

Explanation:

All the possible stable binary arrays are [0,0,1,0,1,1], [0,0,1,1,0,1], [0,1,0,0,1,1], [0,1,0,1,0,1], [0,1,0,1,1,0], [0,1,1,0,0,1], [0,1,1,0,1,0], [1,0,0,1,0,1], [1,0,0,1,1,0], [1,0,1,0,0,1], [1,0,1,0,1,0], [1,0,1,1,0,0], [1,1,0,0,1,0], and [1,1,0,1,0,0].



Constraints:

1 <= zero, one, limit <= 1000

*/


#include"head.h"
class Solution {
	public:
		int numberOfStableArrays(int zero, int one, int limit) {
			const int mod=1e9+7;
			vector<vector<vector<long long>>> dp(zero+1,vector<vector<long long>>(one+1,vector<long long>(2,0)));

			for(int i=0;i<=min(zero,limit);i++)
				dp[i][0][0]=1;
			for(int i=0;i<=min(one,limit);i++)
				dp[0][i][1]=1;

			for(int i=1;i<=zero;i++)
				for(int j=1;j<=one;j++)
				{
					dp[i][j][0]=((long long)dp[i-1][j][0]+dp[i-1][j][1]+(i>limit?mod-dp[i-limit-1][j][1]:0))%mod;
					dp[i][j][1]=((long long)dp[i][j-1][0]+dp[i][j-1][1]+(j>limit?mod-dp[i][j-limit-1][0]:0))%mod;
				}
			return (dp[zero][one][0]+dp[zero][one][1])%mod;
		}
};


int main() 
{
	Solution s;
	cout<<s.numberOfStableArrays(1,1,2)<<endl;
	cout<<s.numberOfStableArrays(1,2,1)<<endl;
	cout<<s.numberOfStableArrays(3,3,2)<<endl;
	return 0;
}

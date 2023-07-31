/*
   Given two positive integers n and x.

   Return the number of ways n can be expressed as the sum of the xth power of unique positive integers, in other words, the number of sets of unique integers [n1, n2, ..., nk] where n = n1x + n2x + ... + nkx.

   Since the result can be very large, return it modulo 109 + 7.

   For example, if n = 160 and x = 3, one way to express n is n = 23 + 33 + 53.



   Example 1:

Input: n = 10, x = 2
Output: 1
Explanation: We can express n as the following: n = 32 + 12 = 10.
It can be shown that it is the only way to express 10 as the sum of the 2nd power of unique integers.

Example 2:

Input: n = 4, x = 1
Output: 2
Explanation: We can express n in the following ways:
- n = 41 = 4.
- n = 31 + 11 = 4.



Constraints:

1 <= n <= 300
1 <= x <= 5

*/


#include"head.h"
class Solution {
	public:
		int numberOfWays(int n, int x) {
		const int mod=1e9+7;
		vector<int> dp(n+1,0);

		dp[0]=1;
		for(int i=1,p=1;p<=n;p=power(++i,x))
			for(int j=n;j>=p;j--)
				dp[j]=(dp[j]+dp[j-p])%mod;
		return dp[n];
		}
		int power(int k,int x)
		{
			int p=1;
			for(;x;x--)
				p*=k;
			return p;
		}
};


int main() 
{
	Solution s;
	cout<<s.numberOfWays(10,2)<<endl;
	cout<<s.numberOfWays(4,1)<<endl;
	return 0;
}

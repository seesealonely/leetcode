/*
   A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits s and all we know is that all integers in the array were in the range [1, k] and there are no leading zeros in the array.

   Given the string s and the integer k, return the number of the possible arrays that can be printed as s using the mentioned program. Since the answer may be very large, return it modulo 109 + 7.



   Example 1:

Input: s = "1000", k = 10000
Output: 1
Explanation: The only possible array is [1000]

Example 2:

Input: s = "1000", k = 10
Output: 0
Explanation: There cannot be an array that was printed this way and has all integer >= 1 and <= 10.

Example 3:

Input: s = "1317", k = 2000
Output: 8
Explanation: Possible arrays are [1317],[131,7],[13,17],[1,317],[13,1,7],[1,31,7],[1,3,17],[1,3,1,7]

Example 4:

Input: s = "2020", k = 30
Output: 1
Explanation: The only possible array is [20,20]. [2020] is invalid because 2020 > 30. [2,020] is ivalid because 020 contains leading zeros.

Example 5:

Input: s = "1234567890", k = 90
Output: 34



Constraints:

1 <= s.length <= 105
s consists of only digits and does not contain leading zeros.
1 <= k <= 109

*/
#include"head.h"
class Solution {
	public:
		int numberOfArrays(string s, int k) {
		return dp(s,k);	
		}
		int dp(string &s, int k) {
		int n=s.size();
		vector<int> dp(n,-1);
		return helper(s,dp,0,k);	
		}
		int helper(string &s,vector<int> &dp,int cur, int k) {
			long res=0,num=0,mod=1e9+7,n=s.size();
			if(cur==n) return 1;
			if(s[cur]=='0') return 0;
			if(dp[cur]>-1) return dp[cur];
			for(int i=cur;i<n;i++)
			{
				num=num*10+s[i]-'0';	
				if(num>k) break;
				res=(res+helper(s,dp,i+1,k))%mod;
			}
			return 	dp[cur]=res;
		}
};

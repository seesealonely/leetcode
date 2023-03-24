/*
   Given a binary string s, you can split s into 3 non-empty strings s1, s2, and s3 where s1 + s2 + s3 = s.

   Return the number of ways s can be split such that the number of ones is the same in s1, s2, and s3. Since the answer may be too large, return it modulo 109 + 7.



   Example 1:

Input: s = "10101"
Output: 4
Explanation: There are four ways to split s in 3 parts where each part contain the same number of letters '1'.
"1|010|1"
"1|01|01"
"10|10|1"
"10|1|01"

Example 2:

Input: s = "1001"
Output: 0

Example 3:

Input: s = "0000"
Output: 3
Explanation: There are three ways to split s in 3 parts.
"0|0|00"
"0|00|0"
"00|0|0"



Constraints:

3 <= s.length <= 105
s[i] is either '0' or '1'.

*/


#include"head.h"
class Solution {
	public:
		int numWays(string s) {
		const int n=s.size(),mod=1e9+7;

		int ones=0;
		for(int i=0;i<n;i++)
			ones+=s[i]=='1';

		if(ones%3)
			return 0;

		if(ones==0)
			return (long long)(n-1)*(n-2)/2%mod;

		ones/=3;
		long long cnt=0,l1=0,l2=0;
		for(int i=0;i<n;i++)
		{
			cnt+=s[i]=='1';
			if(cnt==ones) l1++;
			else if(cnt==2*ones) l2++;
		}
		return (l1*l2)%mod;
		}
};


int main() 
{
	Solution s;
	cout<<s.numWays("10101")<<endl;
	cout<<s.numWays("1001")<<endl;
	cout<<s.numWays("0000")<<endl;
	return 0;
}

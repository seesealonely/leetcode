/*
   Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

   Example 1:
Input:

"bbbab"

Output:

4

One possible longest palindromic subsequence is "bbbb".

Example 2:
Input:

"cbbd"

Output:

2

One possible longest palindromic subsequence is "bb". 
*/

#include"head.h"

class Solution {
	public:
		int longestPalindromeSubseq(string s) {
			return dp(s);        
		}
		int dp(string s)
		{
			if(s.size()<=1) return s.size();
			vector<vector<int> > dp(s.size(),vector<int>(s.size(),0));
			for(int i=0;i<s.size();i++)
				dp[i][i]=1;
			for(int i=1;i<s.size();i++)
				dp[i-1][i]=s[i-1]==s[i]?2:1;
			for(int l=2;l<s.size();l++)
				for(int i=0;i+l<s.size();i++)
						dp[i][i+l]=max(max(dp[i+1][i+l],dp[i][i+l-1]),dp[i+1][i+l-1]+(s[i]==s[i+l]?2:0));	
			return dp.front().back();
		}
};

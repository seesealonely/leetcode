/*
   Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

   '.' Matches any single character.​​​​
   '*' Matches zero or more of the preceding element.

   The matching should cover the entire input string (not partial).



   Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".



Constraints:

1 <= s.length <= 20
1 <= p.length <= 20
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

*/


#include"head.h"
class Solution {
	public:
		bool isMatch(string s, string p) {
		const int m=s.size(),n=p.size();
		vector<vector<int>> dp(m+1,vector<int>(n+1,false));
		dp[0][0]=true;
		for(int i=0;i<=m;i++)
			for(int j=0;j<=n;j++)
				if(p[j-1]=='*')
				{
					dp[i][j]=dp[i][j-2];
					if(i&&(p[j-2]=='.'||p[j-2]==s[i-1]))
						dp[i][j]|=dp[i-1][j];
				}
				else if(i&&(p[j-1]=='.'||p[j-1]==s[i-1]))
					dp[i][j]=dp[i-1][j-1];
		return dp[m][n];
		}
};


int main() 
{
	Solution s;
	cout<<s.isMatch("aa","a")<<endl;
	cout<<s.isMatch("aa","a*")<<endl;
	cout<<s.isMatch("aa",".*")<<endl;
	return 0;
}

/*
   You are given two strings, word1 and word2. You want to construct a string in the following manner:

   Choose some non-empty subsequence subsequence1 from word1.
   Choose some non-empty subsequence subsequence2 from word2.
   Concatenate the subsequences: subsequence1 + subsequence2, to make the string.

   Return the length of the longest palindrome that can be constructed in the described manner. If no palindromes can be constructed, return 0.

   A subsequence of a string s is a string that can be made by deleting some (possibly none) characters from s without changing the order of the remaining characters.

   A palindrome is a string that reads the same forward as well as backward.



   Example 1:

Input: word1 = "cacb", word2 = "cbba"
Output: 5
Explanation: Choose "ab" from word1 and "cba" from word2 to make "abcba", which is a palindrome.

Example 2:

Input: word1 = "ab", word2 = "ab"
Output: 3
Explanation: Choose "ab" from word1 and "a" from word2 to make "aba", which is a palindrome.

Example 3:

Input: word1 = "aa", word2 = "bb"
Output: 0
Explanation: You cannot construct a palindrome from the described method, so return 0.



Constraints:

1 <= word1.length, word2.length <= 1000
word1 and word2 consist of lowercase English letters.

*/
#include"head.h"
class Solution {
	public:
		int longestPalindrome(string word1, string word2) {
			const int len1=word1.size(),len2=word2.size(),len=len1+len2;

			vector<vector<int> > dp(len,vector<int>(len,0));

			for(int i=0;i<len;i++)
				dp[i][i]=1;

			int res=0;
			const string w=word1+word2;

			for(int i=1;i<len;i++)
				for(int j=0;j+i<len;j++)
				{
					if(w[j]==w[j+i])
					{
						dp[j][j+i]=(i==1?2:dp[j+1][j+i-1]+2);
						if(j<len1&&j+i>=len1)
							res=max(res,dp[j][j+i]);
					}
					else
						dp[j][j+i]=max(dp[j+1][j+i],dp[j][j+i-1]);
				}
			return res;
		}
};
int main() 
{
	Solution s;
	cout<<s.longestPalindrome("cacb","cbba")<<endl;
	cout<<s.longestPalindrome("ab","ab")<<endl;
	cout<<s.longestPalindrome("aa","bb")<<endl;
	return 0;
}

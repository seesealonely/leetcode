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

#include"516.LongestPalindromicSubsequence.h"

int main()
{
	Solution s;
	cout<<s.longestPalindromeSubseq("bbbab")<<endl;
	cout<<s.longestPalindromeSubseq("cbbd")<<endl;
	cout<<s.longestPalindromeSubseq("abcdef")<<endl;
	cout<<s.longestPalindromeSubseq("abcabcabcabc")<<endl;
	return 0;
}

/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.

Example:

Input: "cbbd"

Output: "bb"

*/

#include"5.LongestPalindromicSubstring.h"

int main()
{
	string ss("babad");
	Solution s;
	cout<<s.longestPalindrome(ss)<<endl;
	return 0;
}

/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any insertions.

Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".

Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".

Example 4:

Input: s = "g"
Output: 0

Example 5:

Input: s = "no"
Output: 1

 

Constraints:

    1 <= s.length <= 500
    All characters of s are lower case English letters.
*/

#include"head.h"

class Solution {
public:
    int minInsertions(string s) {
	int len=s.size();
	vector<vector<int> > dp(len+1,vector<int>(len+1,0));
	for(int i=0;i<len;i++)
		for(int j=0;j<len;j++)
			dp[i+1][j+1]=s[i]==s[len-1-j]?dp[i][j]+1: max(dp[i][j+1],dp[i+1][j]);
	return len-dp[len][len];
    }
};

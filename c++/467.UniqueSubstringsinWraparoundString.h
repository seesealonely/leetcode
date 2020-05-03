/*
Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".

Now we have another string p. Your job is to find out how many unique non-empty substrings of p are present in s. In particular, your input is the string p and you need to output the number of different non-empty substrings of p in the string s.

Note: p consists of only lowercase English letters and the size of p might be over 10000.

Example 1:

Input: "a"
Output: 1

Explanation: Only the substring "a" of string "a" is in the string s.

Example 2:

Input: "cac"
Output: 2
Explanation: There are two substrings "a", "c" of string "cac" in the string s.

Example 3:

Input: "zab"
Output: 6
Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.
*/
#define c11
#include"head.h"

class Solution {
public:
    int findSubstringInWraproundString(string p) {
	vector<int> dp(26,0);
	int maxLen=1;
	for(int i=0;i<p.size();i++)
	{
		if(i>0&&((p[i]-p[i-1]==1)||(p[i-1]-p[i]==25)))
			maxLen++;
		else
			maxLen=1;
		int index=p[i]-'a';
		dp[index]=max(dp[index],maxLen);
	}
	int res=0;
	for(int i=0;i<dp.size();i++)
		res+=dp[i];
	return res;
    }
};

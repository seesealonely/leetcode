/*
 Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Note:

    The input string length won't exceed 1000.

*/
#include"head.h"

class Solution {
public:
    int countSubstrings(string s) {
	int res=0;
	for(int i=0;i<s.size();++i)
		res+=count(s,i,0)+count(s,s.size()-1,i+1);  
	return res;
    }
	int count(string s,int l,int r)
	{
		int count=0;
		while(l>=0&&r<s.size())
		{
			if(l>=r||s[l]==s[r]) count+=l--<=r++?1:0;
			else break;
		}
		return count;
	}
};

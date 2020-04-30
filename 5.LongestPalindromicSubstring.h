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

#include"head.h"

class Solution {
public:
    string longestPalindrome(string s) {
 	if(s.size()<2) return s;
	int len=s.size(),max_left=0,max_len=1,left,right;
	for(int begin=0;begin<len&&len-begin>max_len/2;)
	{       
		left=right=begin;
		while(right<len-1&&s[right+1]==s[right]) ++right;
		begin=right+1;
		while(right<len-1&&left>0&&s[right+1]==s[left-1])
		{	
			++right; --left;
		}
		if(max_len<right-left+1)
		{
			max_left=left;
			max_len=right-left+1;
		}
	}
		return s.substr(max_left,max_len);
    }
};

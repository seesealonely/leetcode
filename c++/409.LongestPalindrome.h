/*
   Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

   This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

#include"head.h"

class Solution {
	public:
		int longestPalindrome(string s) {
			int lower[26]={0};       
			int upper[26]={0};       
			int res=0;
			bool odd=false;
			for(int i=0;i<s.size();++i)
			{
				if(islower(s[i])) ++lower[s[i]-'a'];
				else ++upper[s[i]-'A'];
			}
			for(int i=0;i<26;++i)
			{
				if(lower[i]%2==0) res+=lower[i];	
				else { res+=lower[i]-1; odd=true;}	
				if(upper[i]%2==0) res+=upper[i];	
				else { res+=upper[i]-1; odd=true;}	
			}
			return odd?++res:res;
		}
};

/*
   You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

   We repeatedly make duplicate removals on s until we no longer can.

   Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.



   Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation:
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move. The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

Example 2:

Input: s = "azxxzy"
Output: "ay"



Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.

*/
#include"head.h"
class Solution {
	public:
		string removeDuplicates(string s) {
		return usingTwoPointers(s);
		return usingStack(s);
		}
		string usingStack(string s)
		{
			string res;
			for(int i=0;i<s.size();i++)
			if(res.empty()||s[i]!=res.back())
				res+=s[i];
			else
				res.pop_back();
			return res;
		}
		string usingTwoPointers(string s)
		{
			int i=0,j=0,n=s.size();
			for(;j<n;i++,j++)
			{
				s[i]=s[j];
				if(i>0&&s[i-1]==s[i])
					i-=2;
			}
			return s.substr(0,i);
		}
};

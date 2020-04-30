/*
   Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.

Example:

Input: s = "abcdefg", k = 2
Output: "bacdfeg"

Restrictions:

The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
*/

#include"head.h"

class Solution {
	public:
		string reverseStr(string s, int k) {
			for(int i=0;i<s.size()+1;)
			{
				if(i<=s.size()-1&&i+k-1<=s.size()-1)
				{
					reverse(s,i,i+k-1);
					i+=2*k;
				}
				else 
				{
					reverse(s,i,s.size()-1);
					break;
				}	
			} 
			return s;
		}
	private:
		inline void reverse(string &s,int begin,int end)
		{
			int temp;
			for(;begin<end;++begin,--end)
			{
				temp=s[begin];
				s[begin]=s[end];
				s[end]=temp;
			}
		}
};

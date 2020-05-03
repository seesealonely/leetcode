/*
   Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

   For "(()", the longest valid parentheses substring is "()", which has length = 2.

   Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 
   */

#include"head.h"

class Solution {
	public:
		int longestValidParentheses(string s) {
			stack<int> st;
			for(int i=0;i<s.size();++i)
			{
				if(s[i]=='(') st.push(i);
				else
					if(st.empty()) st.push(i);
					else
					{
						if(s[st.top()]=='(') st.pop();
						else st.push(i);
					}
			}
			if(st.empty()) return s.size();
			int lastestIndex=s.size(),preLast=0,res=0;
			while(!st.empty())
			{
				preLast=st.top();
				st.pop();
				res=max(res,lastestIndex-preLast-1);
				lastestIndex=preLast;
			}
			res=max(res,lastestIndex);
			return res;
		}
};

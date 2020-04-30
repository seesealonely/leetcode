/*
   Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

   For "(()", the longest valid parentheses substring is "()", which has length = 2.

   Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 
   */

#include"32.LongestValidParentheses.h"

int main()
{
	string ss(")()())");
	string ss1("())");
	Solution s;
	cout<<s.longestValidParentheses(ss)<<endl;
	cout<<s.longestValidParentheses(ss1)<<endl;
	return 0;
}

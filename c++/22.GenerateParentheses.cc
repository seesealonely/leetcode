/*
   Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

   For example, given n = 3, a solution set is:

   [
   "((()))",
   "(()())",
   "(())()",
   "()(())",
   "()()()"
   ]

*/

#include"22.GenerateParentheses.h"

int main()
{
	Solution s;
	show(s.generateParenthesis(4));	
	return 0;
}

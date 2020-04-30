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

#include"head.h"

class Solution {
	public:
	
		vector<string> generateParenthesis(int n) {
		vector<string> res;
		string one;
		dfs(one,res,n,0);
		return res;
		}
	private:
		void dfs(string one,vector<string> &res,int left,int right)
		{
			if(!left&&!right)
			{
			 res.push_back(one);
			return;
			}
			if(right>0) dfs(one+")",res,left,right-1); 
			if(left>0) dfs(one+"(",res,left-1,right+1); 
		}
};

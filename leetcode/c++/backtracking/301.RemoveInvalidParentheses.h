/*
   Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

   Return all the possible results. You may return the answer in any order.



   Example 1:

Input: s = "()())()"
Output: ["(())()","()()()"]

Example 2:

Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]

Example 3:

Input: s = ")("
Output: [""]



Constraints:

1 <= s.length <= 25
s consists of lowercase English letters and parentheses '(' and ')'.
There will be at most 20 parentheses in s.

*/
#include"head.h"
class Solution {
	public:
		vector<string> removeInvalidParentheses(string s) {
			vector<string> res;
			int cntl=0,cntr=0;
			for(int i=0;i<s.size();i++)
			{
				if(s[i]=='(')
				cntl++;
				else if(isalpha(s[i]))
						;
				else
				{
				if(cntl==0)
					cntr++;
				else if(cntl)
					cntl-=s[i]==')';
				}
			}	
			dfs(cntl,cntr,0,s,res);
			return res;
		}
		void dfs(int cntl,int cntr,int start,string s,vector<string> &res)
		{
			if(cntl==0&&cntr==0)
			{
				if(check(s))
				res.push_back(s);
				return;
			}
			for(int i=start;i<s.size();i++)
			{
				if(i!=start&&s[i]==s[i-1]) continue;
				if(cntl>0&&s[i]=='(')
					dfs(cntl-1,cntr,i,s.substr(0,i)+s.substr(i+1),res);
				if(cntr>0&&s[i]==')')
					dfs(cntl,cntr-1,i,s.substr(0,i)+s.substr(i+1),res);
			}
		}
		bool check(string s)
		{
			int cnt=0;
			for(int i=0;i<s.size();i++)
			{
				if(s[i]=='(')
				cnt++;
				else if(isalpha(s[i]))
						;
				else
				if(--cnt<0)
					return false;
			}
			return cnt==0;
		}
};

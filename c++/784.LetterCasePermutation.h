/*
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]

Note:

    S will be a string with length at most 12.
    S will consist only of letters or digits.
*/

#include"head.h"

void dfs(int begin,vector<string> &res,string &s)
{
	if(begin==s.size())
	{
	res.push_back(s);
	return;
	}
	if(isalpha(s[begin]))
	{
		if(isupper(s[begin]))
		{
		dfs(begin+1,res,s);
			s[begin]+=32;
		dfs(begin+1,res,s);
		}
		else
		{
		dfs(begin+1,res,s);
			s[begin]-=32;
		dfs(begin+1,res,s);
		}
	}
	else
		dfs(begin+1,res,s);
}
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
       vector<string> res;
	dfs(0,res,S);
	return res;
    }
};

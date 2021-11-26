/*
   Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.

   Return all such possible sentences.

   For example, given
   s = "catsanddog",
   dict = ["cat", "cats", "and", "sand", "dog"].

   A solution is ["cats and dog", "cat sand dog"]. 
   */

#define c11
#include"head.h"

class Solution {
	public:
		vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> wd(wordDict.begin(),wordDict.end());
		vector<string> res;
		backTrace(0,0,"",s,wd,res);
		return res;
		}
		void backTrace(int start,int len,string cur,string &s,unordered_set<string> &wd,vector<string> &res)
		{
			if(start==s.size())
			{
				if(len==s.size())
					res.push_back(cur.substr(1));
				return;
			}
			for(int i=1;start+i<=s.size()&&i<=s.size();i++)
			{
				string sub=s.substr(start,i);
				if(wd.count(sub))
						backTrace(start+i,len+i,cur+" "+sub,s,wd,res);
			}
		}
};

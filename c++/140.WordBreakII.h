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
			return dp(s,wordDict);
			/*
			   unordered_map<string,vector<string> > hash;
			   return help(s,wordDict,hash);		
			   */
		}
		vector<string> dp(string s, vector<string>& wordDict) {
			int slen=s.size();
			vector<vector<string> > dp(slen+1);
			unordered_set<string> set(wordDict.begin(),wordDict.end());
			dp[0].emplace_back("");
			for(int i=1;i<=s.size();i++)
			{
				for(int j=i-1;j>=0;j--)
				{
					string sub=s.substr(j,i-j);
					if(dp[j].size()>0&&set.count(sub))
					{
					for(int k=0;k<dp[j].size();k++)
						dp[i].emplace_back(dp[j][k]+(dp[j][k].empty()?"":" ")+sub);
					}
				}
			}
			return dp[slen];

		}
		vector<string> help(string s, vector<string>& wordDict,unordered_map<string,vector<string> > hash) {
			if(hash.count(s)) return hash[s];
			if(s.empty()) return {""};
			vector<string> res;
			for(int i=0;i<wordDict.size();i++)
			{
				if(wordDict[i]!=s.substr(0,wordDict[i].size()))
					continue;
				vector<string> sub=help(s.substr(wordDict[i].size()),wordDict,hash);
				for(int j=0;j<sub.size();j++)
					res.push_back(wordDict[i]+(sub[j].empty()?"":" ")+sub[j]);
			}
			return hash[s]=res;
		}
};

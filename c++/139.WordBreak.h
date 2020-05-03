/*
   Given a non-empty string s and a wordDictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more wordDictionary words. You may assume the wordDictionary does not contain duplicate words.

   For example, given
   s = "leetcode",
   wordDict = ["leet", "code"].

   Return true because "leetcode" can be segmented as "leet code". 
   */

#include"head.h"

class Solution {
	public:
		bool wordBreak(string s, vector<string>& wordDict) {
			if(wordDict.empty()) return false;
			vector<bool> dp(s.size()+1,false);
			string word;
			dp[0]=true;
			for(int i=1;i<=s.size();++i)
			{
				for(int j=i-1;j>=0;--j)
				if(dp[j])
				{
					word=s.substr(j,i-j);
					for(int k=0;k<wordDict.size();++k)
						if(wordDict[k]==word)
						{
							dp[i]=true;
							break;
						}
				}
			} 	       
			return dp[s.size()];
		}
};

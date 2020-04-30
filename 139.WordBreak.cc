/*
   Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

   For example, given
   s = "leetcode",
   dict = ["leet", "code"].

   Return true because "leetcode" can be segmented as "leet code". 
   */

#include"139.WordBreak.h"

int main()
{
	vector<string> d;
	d.push_back("leet");
	d.push_back("code");
	Solution s;
	cout<<s.wordBreak("leetcode",d)<<endl;
	return 0;
}

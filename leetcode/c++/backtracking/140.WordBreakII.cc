/*
 Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"]. 
*/

#include"140.WordBreakII.h"

int main()
{
	Solution s;
	vector<string> v={"cat", "cats", "and", "sand", "dog"};	
	show(s.wordBreak("catsanddog",v));
	return 0;
}

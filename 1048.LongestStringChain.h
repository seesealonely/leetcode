/*
Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

 

Example 1:

Input: ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: one of the longest word chain is "a","ba","bda","bdca".

 

Note:

    1 <= words.length <= 1000
    1 <= words[i].length <= 16
    words[i] only consists of English lowercase letters.

*/
#define c11
#include"head.h"

class Solution {
public:
    int longestStrChain(vector<string>& words) {
	unordered_map<string,int> hash;
	int res=0;
	sort(words.begin(),words.end(),compare);
	for(int i=0;i<words.size();i++)
	{
		int curMax=0;
		for(int j=0;j<words[i].size();j++)
		{
			string w=words[i].substr(0,j)+words[i].substr(j+1);	
			curMax=max(curMax,hash[w]+1);	
		}	
		hash[words[i]]=curMax;
	}
	for(auto it=hash.begin();it!=hash.end();it++)
	res=max(res,it->second);
	return res;
    }
	static	bool compare(string a,string b)
	{
		return a.size()<b.size();
	}
};

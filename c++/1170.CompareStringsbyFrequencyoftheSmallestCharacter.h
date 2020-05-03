/*
Let's define a function f(s) over a non-empty string s, which calculates the frequency of the smallest character in s. For example, if s = "dcce" then f(s) = 2 because the smallest character is "c" and its frequency is 2.

Now, given string arrays queries and words, return an integer array answer, where each answer[i] is the number of words such that f(queries[i]) < f(W), where W is a word in words.

 

Example 1:

Input: queries = ["cbd"], words = ["zaaaz"]
Output: [1]
Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").

Example 2:

Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
Output: [1,2]
Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") are both > f("cc").

 

Constraints:

    1 <= queries.length <= 2000
    1 <= words.length <= 2000
    1 <= queries[i].length, words[i].length <= 10
    queries[i][j], words[i][j] are English lowercase letters.


*/

#include"head.h"

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
       	vector<int> fre(12),res;
	for(int i=0;i<words.size();i++)
		fre[hash(words[i])]++;
	for(int i=9;i>=0;i--)
		fre[i]+=fre[i+1]; 
	for(int i=0;i<queries.size();i++)
		res.push_back(fre[hash(queries[i])+1]);	
	return res;
    }
	int hash(string s)
	{
		int h[26]={};
		for(int i=0;i<s.size();i++)
			h[s[i]-'a']++;
		for(int i=0;i<26;i++)
		if(h[i])	return h[i];
		return 0;
	}
};

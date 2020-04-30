/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:

    pattern = "abba", str = "dog cat cat dog" should return true.
    pattern = "abba", str = "dog cat cat fish" should return false.
    pattern = "aaaa", str = "dog cat cat dog" should return false.
    pattern = "abba", str = "dog dog dog dog" should return false.

Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space. 
*/

#include"head.h"

class Solution {
public:
    bool wordPattern(string pattern, string str) {
 	map<char,int> mp;
	map<string,int> ms;
	istringstream in(str);
	int i=0,n=pattern.size();
	for(string word;in>>word;++i)
	{
	if(i==n||mp[pattern[i]]!=ms[word]) 
		return false;
	mp[pattern[i]]=ms[word]=i+1;
	}
	return i==n;
    }
};

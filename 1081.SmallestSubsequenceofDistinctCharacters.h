/*
Return the lexicographically smallest subsequence of text that contains all the distinct characters of text exactly once.

 

Example 1:

Input: "cdadabcc"
Output: "adbc"

Example 2:

Input: "abcd"
Output: "abcd"

Example 3:

Input: "ecbacba"
Output: "eacb"

Example 4:

Input: "leetcode"
Output: "letcod"

 

Note:

    1 <= text.length <= 1000
    text consists of lowercase English letters.

*/

#include"head.h"

class Solution {
public:
    string smallestSubsequence(string text) {
 	string res;
	vector<int> hash(26,0);
	vector<bool> visit(26,false);
	for(int i=0;i<text.size();i++)
		hash[text[i]-'a']=i; 
	for(int i=0;i<text.size();i++)
	{
		if(visit[text[i]-'a']) continue;
		while(!res.empty()&&res.back()>text[i]&&i<hash[res.back()-'a'])
		{
			visit[res.back()-'a']=false;
			res.pop_back();
		}
		res.push_back(text[i]);
		visit[text[i]-'a']=true;	
	}
	return res;
    }
};

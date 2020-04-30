/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example 1:

Input: "bcabc"
Output: "abc"

Example 2:

Input: "cbacdcbc"
Output: "acdb"

*/

#define c11

#include"head.h"

class Solution {
public:
    string removeDuplicateLetters(string s) {
	vector<int> count(26,0);	        
	vector<bool> visit(26,false);	        	        
	string st;
	for(int i=0;i<s.size();i++)
		count[s[i]-'a']++;
	for(int i=0;i<s.size();i++)
	{
		--count[s[i]-'a'];
		if(visit[s[i]-'a']) continue;
		while(!st.empty()&&count[st.back()-'a']&&s[i]<st.back())
		{
			visit[st.back()-'a']=false;
			st.pop_back();
		}
		visit[s[i]-'a']=true;
		st+=s[i];
	}
	return st;
    }
};

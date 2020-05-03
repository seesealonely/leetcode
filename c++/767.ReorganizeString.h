/*
Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"

Example 2:

Input: S = "aaab"
Output: ""

Note:

    S will consist of lowercase letters and have length in range [1, 500].
*/

#include"head.h"

class Solution {
public:
    string reorganizeString(string S) {
	vector<int> count(26,0);
	string res;
	for(int i=0;i<S.size();i++)
	{
		int num=++count[S[i]-'a'];
		if(num>(1+S.size())/2) return "";
	}        
	priority_queue<pair<int,char> >pq;
	for(int i=0;i<26;i++)
	if(count[i]) pq.push({count[i],'a'+i});
	while(!pq.empty())
	{
		pair<int,char> pre,cur;
		pre=pq.top();pq.pop();
		if(res.empty()||pre.second!=res[res.size()-1])
		{
			res+=pre.second;
			if(--pre.first>0)
				pq.push(pre);
		}
		else
		{
			cur=pq.top();pq.pop();
			res+=cur.second;
			if(--cur.first>0)
				pq.push(cur);
				pq.push(pre);
		}
	}
	return res;
    }
};

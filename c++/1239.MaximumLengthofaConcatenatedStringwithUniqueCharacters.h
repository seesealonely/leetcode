/*
Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which have unique characters.

Return the maximum possible length of s.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.

Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible solutions are "chaers" and "acters".

Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26

 

Constraints:

    1 <= arr.length <= 16
    1 <= arr[i].length <= 26
    arr[i] contains only lower case English letters.
*/
#define c11
#include"head.h"

class Solution {
public:
    int maxLength(vector<string>& arr) {
	return dp(arr);
    }
    int dp(vector<string>& arr) {
	vector<bitset<26> > dp{bitset<26>()};
	int res=0;
	for(int i=0;i<arr.size();i++)
	{
		int n=arr[i].size();
		bitset<26> cur;
		for(int j=0;j<arr[i].size();j++)
		cur.set(arr[i][j]-'a');
		if(cur.size()<n) continue;	
		
		for(int j=dp.size()-1;j>=0;j--)
		{
			bitset<26> c=dp[j];
			if((c&cur).any()) continue;	
			dp.push_back(c|cur);
			res=max(res,(int)c.count()+n);
		}
	}
		return res;
    }
    int dfs(vector<string>& arr,string sub="",int b=0) {
	unordered_set<char> s(sub.begin(),sub.end());
	if(s.size()!=sub.size())
	return 0;
	int res=s.size();
	for(int i=0;i<arr.size();i++)
	res=max(res,dfs(arr,sub+arr[i],i+1));
	return res;
    }
};

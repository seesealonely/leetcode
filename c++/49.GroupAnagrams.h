/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    All inputs will be in lowercase.
    The order of your output does not matter.

*/

#define c11

#include"head.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
 	vector<vector<string> > res;
	unordered_map<string,vector<string> > m;
	for(int i=0;i<strs.size();i++)
	{
		string tmp=strs[i];
		sort(tmp.begin(),tmp.end());
		m[tmp].push_back(strs[i]);
	}       
	for(unordered_map<string,vector<string> >::iterator it=m.begin();it!=m.end();it++)
	res.push_back(it->second);
	return res;
    }
};

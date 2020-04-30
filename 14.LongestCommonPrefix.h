/*
Write a function to find the longest common prefix string amongst an array of strings. 
*/

#include"head.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
 	string res;
	for(int i=0;i<strs[0].size();res+=strs[0][i],++i)
		for(int j=0;j<strs.size();++j)       
		if(i>=strs[j].size()||(j>0&&strs[j][i]!=strs[j-1][i]))
			return res;
	return res;
    }
};

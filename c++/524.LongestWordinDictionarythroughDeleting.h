/*
 Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:

Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"

Example 2:

Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"

Note:

    All the strings in the input will only contain lower-case letters.
    The size of the dictionary won't exceed 1,000.
    The length of all the strings in the input won't exceed 1,000.

*/

#include"head.h"

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
	string res;
 	for(int i=0;i<d.size();i++)
	{
		int si=0,di=0;
		while(si<s.size()&&di<d[i].size())
		{
			if(s[si]==d[i][di])
				si++,di++;
			else
				si++;
		}
		if(di==d[i].size()&&(res.size()<d[i].size()||res.size()==d[i].size()&&res>d[i]))
		res=d[i];
	}       
	return res;
    }
};

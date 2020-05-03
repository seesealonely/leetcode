/*
 Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3. 
*/

#include"head.h"

class Solution {
public:
    int numDistinct(string s, string t) {
 	int sLen=s.size(),tLen=t.size();
	if(tLen>sLen) return 0;
	vector<vector<int> > path(tLen+1,vector<int>(sLen+1,0));
	for(int k=0;k<=sLen;k++) path[0][k]=1;
	for(int i=1;i<sLen+1;++i)
	for(int j=1;j<tLen+1;++j)
		path[j][i]=path[j][i-1]+(t[j-1]==s[i-1]?path[j-1][i-1]:0); 
	return path[tLen][sLen];
    }
};

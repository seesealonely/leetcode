/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.  If multiple answers exist, you may return any of them.

(A string S is a subsequence of string T if deleting some number of characters from T (possibly 0, and the characters are chosen anywhere from T) results in the string S.)

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.

 

Note:

    1 <= str1.length, str2.length <= 1000
    str1 and str2 consist of lowercase English letters.


*/

#include"head.h"

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
	string lcs=LCS(str1,str2);        
	string res="";
	int i=0,j=0;
	for(int l=0;l<lcs.size();l++,i++,j++)
	{
		while(str1[i]!=lcs[l])
			res+=str1[i++];
		while(str2[j]!=lcs[l])
			res+=str2[j++];
		res+=lcs[l];
	}
	return res+str1.substr(i)+str2.substr(j);
    }
    string LCS(string str1, string str2) {
       vector<vector<string> > dp(str1.size()+1,vector<string> (str2.size()+1,"")); 
	for(int i=0;i<str1.size();i++)
		for(int j=0;j<str2.size();j++)
		if(str1[i]==str2[j])
			dp[i+1][j+1]=dp[i][j]+str1[i];
		else
			dp[i+1][j+1]=dp[i+1][j].size()>dp[i][j+1].size()?dp[i+1][j]:dp[i][j+1];
	return dp[str1.size()][str2.size()];
    }
};

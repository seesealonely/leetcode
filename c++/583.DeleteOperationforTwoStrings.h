/*
 Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

Example 1:

Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Note:

    The length of given words won't exceed 500.
    Characters in given words can only be lower-case letters.
*/

#include"head.h"
int dp(string w1,string w2)
{
	vector<vector<int> > dp(w1.size()+1,vector<int>(w2.size()+1,0));
	for(int i=0;i<w1.size();i++)
	for(int j=0;j<w1.size();j++)
	if(w1[i]==w2[j])
		dp[i+1][j+1]=1+dp[i][j];	
	else
		dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
	return w1.size()+w2.size()-2*dp[w1.size()][w2.size()];
}
class Solution {
public:
    int minDistance(string word1, string word2) {
       return dp(word1,word2); 
    }
};

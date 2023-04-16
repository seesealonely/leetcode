/*
   You are given a list of strings of the same length words and a string target.

   Your task is to form target using the given words under the following rules:

   target should be formed from left to right.
   To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
   Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
   Repeat the process until you form the string target.

   Notice that you can use multiple characters from the same string in words provided the conditions above are met.

   Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.



   Example 1:

Input: words = ["acca","bbbb","caca"], target = "aba"
Output: 6
Explanation: There are 6 ways to form target.
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")

Example 2:

Input: words = ["abba","baab"], target = "bab"
Output: 4
Explanation: There are 4 ways to form target.
"bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
"bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
"bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
"bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")



Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 1000
All strings in words have the same length.
1 <= target.length <= 1000
words[i] and target contain only lowercase English letters.

*/


#include"head.h"
class Solution {
	public:
		int numWays(vector<string>& words, string target) {
		const int r=words.size(),c=words[0].size(),tlen=target.size();
		const int mod=1e9+7;
		vector<vector<int>> cnt(c+1,vector<int>(26,0));
		for(int j=0;j<c;j++)
			for(int i=0;i<r;i++)
				cnt[j+1][words[i][j]-'a']++;

		vector<vector<int>> dp(tlen+1,vector<int>(c+1,0));
		for(int i=0;i<=c;i++)
			dp[0][i]=1;

		for(int i=1;i<=tlen;i++)
			for(int j=1;j<=c;j++)
			{
				int c=target[i-1]-'a';
				dp[i][j]=((long long )dp[i-1][j-1]*cnt[j][c]+dp[i][j-1])%mod;
			}

		return dp[tlen][c];
		}
};


int main() 
{
	Solution s;
	vector<string> v={"acca","bbbb","caca"};
	cout<<s.numWays(v,"aba")<<endl;
	v.clear();v={"abba","baab"};
	cout<<s.numWays(v,"bab")<<endl;
	return 0;
}

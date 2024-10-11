/*
   You are given an array of strings words and a string target.

   A string x is called valid if x is a
   prefix
   of any string in words.

   Return the minimum number of valid strings that can be concatenated to form target. If it is not possible to form target, return -1.



   Example 1:

Input: words = ["abc","aaaaa","bcdef"], target = "aabcdabc"

Output: 3

Explanation:

The target string can be formed by concatenating:

Prefix of length 2 of words[1], i.e. "aa".
Prefix of length 3 of words[2], i.e. "bcd".
Prefix of length 3 of words[0], i.e. "abc".

Example 2:

Input: words = ["abababab","ab"], target = "ababaababa"

Output: 2

Explanation:

The target string can be formed by concatenating:

Prefix of length 5 of words[0], i.e. "ababa".
Prefix of length 5 of words[0], i.e. "ababa".

Example 3:

Input: words = ["abcdef"], target = "xyz"

Output: -1



Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 5 * 103
The input is generated such that sum(words[i].length) <= 105.
words[i] consists only of lowercase English letters.
1 <= target.length <= 5 * 103
target consists only of lowercase English letters.

*/


#include"head.h"
class Solution {
	public:

		class node{
			public:
				node *next[26];
				node()
				{
					for(int i=0;i<26;i++)
						next[i]=NULL;
				}
		};
		int minValidStrings(vector<string>& words, string target) {
			node *root=new node();
			for(int i=0;i<words.size();i++)
			{
				node *cur=root;
				for(int j=0;j<words[i].size();j++)
				{
					int c=words[i][j]-'a';
					if(!cur->next[c])
						cur->next[c]=new node();
					cur=cur->next[c];
				}
			}

			const int n=target.size();
			vector<int> dp(n+1,INT_MAX);
			dp[0]=0;
			for(int i=0;i<n;i++)
			{
				if(dp[0]==INT_MAX)
					continue;
				node *cur=root;
				for(int j=i;j<n;j++)
				{
					int c=target[j]-'a';
					if(!cur->next[c])
						break;
					dp[j+1]=min(dp[j+1],dp[i]+1);
					cur=cur->next[c];
				}
			}
			return dp.back()==INT_MAX?-1:dp.back();
		}
};


int main() 
{
	Solution s;
	vector<string> words = {"abc","aaaaa","bcdef"};
	cout<<s.minValidStrings(words,"aabcdabc")<<endl;
	words.clear();
	 words = {"abababab","ab"};
	cout<<s.minValidStrings(words,"ababaababa")<<endl;
	words.clear();
	 words = {"abcdef"};
	cout<<s.minValidStrings(words,"xyz")<<endl;
	return 0;
}

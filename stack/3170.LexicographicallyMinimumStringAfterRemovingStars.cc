/*
   You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.

   While there is a '*', do the following operation:

   Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.

   Return the
   lexicographically smallest
   resulting string after removing all '*' characters.



   Example 1:

Input: s = "aaba*"

Output: "aab"

Explanation:

We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.

Example 2:

Input: s = "abc"

Output: "abc"

Explanation:

There is no '*' in the string.



Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters and '*'.
The input is generated such that it is possible to delete all '*' characters.

*/


#include"head.h"
class Solution {
	public:
		string clearStars(string s) {
			vector<int> st[26];
			const int n=s.size();
			for(int i=0;i<n;i++)
			{
				if(s[i]!='*')
				{
					st[s[i]-'a'].push_back(i);
					continue;
				}
				for(int j=0;j<26;j++)
					if(!st[j].empty())
					{
						st[j].pop_back();
						break;
					}
			}
			vector<int> idx;
			for(int i=0;i<26;i++)
				if(!st[i].empty())
					idx.insert(idx.end(),st[i].begin(),st[i].end());
			sort(idx.begin(),idx.end());

			const int m=idx.size();
			string res(m,' ');
			for(int i=0;i<m;i++)
				res[i]=s[idx[i]];
			return res;
		}
};


int main() 
{
	Solution s;
	cout<<s.clearStars("aaba*")<<endl;
	cout<<s.clearStars("abc")<<endl;
	return 0;
}

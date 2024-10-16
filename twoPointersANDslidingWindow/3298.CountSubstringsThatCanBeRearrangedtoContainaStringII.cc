/*
   You are given two strings word1 and word2.

   A string x is called valid if x can be rearranged to have word2 as a
   prefix
   .

   Return the total number of valid
   substrings
   of word1.

   Note that the memory limits in this problem are smaller than usual, so you must implement a solution with a linear runtime complexity.



   Example 1:

Input: word1 = "bcca", word2 = "abc"

Output: 1

Explanation:

The only valid substring is "bcca" which can be rearranged to "abcc" having "abc" as a prefix.

Example 2:

Input: word1 = "abcabc", word2 = "abc"

Output: 10

Explanation:

All the substrings except substrings of size 1 and size 2 are valid.

Example 3:

Input: word1 = "abcabc", word2 = "aaabc"

Output: 0



Constraints:

1 <= word1.length <= 106
1 <= word2.length <= 104
word1 and word2 consist only of lowercase English letters.

*/


#include"head.h"
class Solution {
	public:
		long long validSubstringCount(string word1, string word2) {
			vector<int> cnt(26,0);
			for(int i=0;i<word2.size();i++)
				cnt[word2[i]-'a']++;

			int zero=0;
			for(int i=0;i<26;i++)
				if(cnt[i]==0)
					zero++;

			const int n=word1.size();
			long long res=0;
			int w=0;
			vector<int> wcnt(26,0);
			for(int l=0,r=0;r<n;r++)
			{
				int c=word1[r]-'a';
				if(++wcnt[c]==cnt[c])
					++w;
				while(w+zero==26)
				{
					c=word1[l++]-'a';
					if(--wcnt[c]<cnt[c])
						--w;
				}
				res+=l;
			}
			return res;
		}
};


int main() 
{
	Solution s;
	cout<<s.validSubstringCount("bcca","abc")<<endl;
	cout<<s.validSubstringCount("ababc","abc")<<endl;
	cout<<s.validSubstringCount("ababc","aaabc")<<endl;
	return 0;
}

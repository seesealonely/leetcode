/*
   Strings s1 and s2 are k-similar (for some non-negative integer k) if we can swap the positions of two letters in s1 exactly k times so that the resulting string equals s2.

   Given two anagrams s1 and s2, return the smallest k for which s1 and s2 are k-similar.



   Example 1:

Input: s1 = "ab", s2 = "ba"
Output: 1

Example 2:

Input: s1 = "abc", s2 = "bca"
Output: 2

Example 3:

Input: s1 = "abac", s2 = "baca"
Output: 2

Example 4:

Input: s1 = "aabc", s2 = "abca"
Output: 2



Constraints:

1 <= s1.length <= 20
s2.length == s1.length
s1 and s2 contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}.
s2 is an anagram of s1.

*/
#define c11
#include"head.h"
class Solution {
	public:
		int kSimilarity(string s1, string s2) {
			if(s1==s2) return 0;
			unordered_set<string> visit;
			queue<string> qu;
			visit.insert(s1);
			qu.push(s1);
			int res=0;
			while(!qu.empty())
			{
				res++;
				for(int size=qu.size();size>0;size--)
				{
					string s=qu.front();qu.pop();visit.erase(s);
					int i=0;
					while(s[i]==s2[i]) i++;
					for(int j=i+1;j<s.size();j++)
					{
						if(s[j]==s2[j]||s[j]!=s2[i]) continue;
						string tmp=swap(s,i,j);
						if(tmp==s2) return res;
						if(visit.find(tmp)==visit.end())
						{	qu.push(tmp);visit.insert(tmp);}
					}
				}
			}
			return res;
		}
		string swap(string s,int i,int j)
		{
			char c=s[i];
			s[i]=s[j];
			s[j]=c;
			return s;
		}

};

/*
   Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.

   For a given query word, the spell checker handles two categories of spelling mistakes:

Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)

In addition, the spell checker operates under the following precedence rules:

When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
When the query matches a word up to capitlization, you should return the first such match in the wordlist.
When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
If the query has no matches in the wordlist, you should return the empty string.

Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].



Example 1:

Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]

Example 2:

Input: wordlist = ["yellow"], queries = ["YellOw"]
Output: ["yellow"]



Constraints:

1 <= wordlist.length, queries.length <= 5000
1 <= wordlist[i].length, queries[i].length <= 7
wordlist[i] and queries[i] consist only of only English letters.

*/

#define c11
#include"head.h"

class Solution {
	public:
		vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
			unordered_set<string> h1;
			unordered_set<char> vow({'a','e','i','u','o'});
			unordered_map<string,int> h2,h3;
			const int w=wordlist.size(),q=queries.size();

			for(int i=0;i<w;i++)
			{
				string s=wordlist[i];

				h1.insert(s);

				for(int j=0;j<s.size();j++)
					if(s[j]>='A'&&s[j]<='Z')
						s[j]=s[j]-'A'+'a';
				if(h2.find(s)==h2.end())
				h2[s]=i;

				for(int j=0;j<s.size();j++)
					if(vow.find(s[j])!=vow.end())
						s[j]='@';
				if(h3.find(s)==h3.end())
				h3[s]=i;
			}

			vector<string> res(q,"");
			for(int i=0;i<q;i++)
			{
				string s=queries[i];
				if(h1.find(s)!=h1.end())
					res[i]=s;
				else 
				{
					for(int j=0;j<s.size();j++)
						if(s[j]>='A'&&s[j]<='Z')
							s[j]=s[j]-'A'+'a';
					if(h2.find(s)!=h2.end())
					{
						res[i]=wordlist[h2[s]];
						continue;
					}

					for(int j=0;j<s.size();j++)
						if(vow.find(s[j])!=vow.end())
							s[j]='@';
					if(h3.find(s)!=h3.end())
						res[i]=wordlist[h3[s]];
				}
			}
			return res;
		}
};

int main()
{
	Solution s;
	vector<string> w={"KiTe","kite","hare","Hare"},q={"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
	show(s.spellchecker(w,q));
	w.clear();w={"yellow"};
	q.clear();q={"YellOw"};
	show(s.spellchecker(w,q));
	return 0;
}
